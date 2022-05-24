#include "bf.h"
#include "error.h"
#include <stdlib.h>
#include <stdio.h>
#include "data.h"

//
// Type Definitions
//

typedef void (*bf_call_t)(bf_t *);

//
// Auxilliary Definitions
//

void bf_do_nothing();
void bf_exit(bf_t *);
void bf_exit_error(bf_t *);
void bf_comment(bf_t *);
void bf_inc_mem(bf_t *);
void bf_dec_mem(bf_t *);
void bf_inc_loc(bf_t *);
void bf_dec_loc(bf_t *);
void bf_write_mem(bf_t *);
void bf_read_mem(bf_t *);
void bf_start_loop(bf_t *);
void bf_end_loop(bf_t *);
bf_call_t bf_parse(char c);

//
// 'bf.h' Implementations
//

bf_t *bf_create(FILE *program) {
    bf_t *bf = (bf_t *)malloc(sizeof(bf_t));
    bf->program = program;
    bf->mem = (int *)malloc(BF_MEMORY_SIZE * sizeof(int));
    bf->func_ptr_stack = stack_create(NULL, NULL);
    bf->exit_code = BF_RUNNING;
}

void bf_delete(bf_t *bf) {
    stack_delete(bf->func_ptr_stack);
    free(bf->mem);
    free(bf);
}

void bf_step(bf_t *bf) {
    char c;
    fscanf(bf->program, "%c", &c);
    bf_call_t call = bf_parse(c);
    if (call == bf_comment || !bf->in_comment)
        call(bf);
    if (bf->exit_code == BF_ERROR)
        make_error("BF error code");
    if (bf->exit_code == BF_CLOSED) {
        printf("\n");
        exit(0);
    }
    bf_step(bf);
}

//
// Auxilliary Implementations
//

void bf_do_nothing() {}

void bf_exit(bf_t *bf) {
    bf->exit_code = BF_CLOSED;
}

void bf_exit_error(bf_t *bf) {
    bf->exit_code = BF_ERROR;
}

void bf_comment(bf_t *bf) {
    bf->in_comment = !bf->in_comment;
}

void bf_inc_mem(bf_t *bf) {
    ++bf->mem[bf->loc];
}

void bf_dec_mem(bf_t *bf) {
    --bf->mem[bf->loc];
}

void bf_inc_loc(bf_t *bf) {
    ++bf->loc;
}

void bf_dec_loc(bf_t *bf) {
    --bf->loc;
}

void bf_write_mem(bf_t *bf) {
    printf("%d", bf->mem[bf->loc]);
}

void bf_read_mem(bf_t *bf) {
    scanf("%d", &bf->mem[bf->loc]);
}

void bf_write_char(bf_t *bf) {
    printf("%c", (char)bf->mem[bf->loc]);
}

void bf_read_char(bf_t *bf) {
    scanf("%c", (char *)&bf->mem[bf->loc]);
}

void bf_start_loop(bf_t *bf) {
    stack_push(bf->func_ptr_stack, (data_t)ftell(bf->program));
}

void bf_end_loop(bf_t *bf) {
    if (bf->mem[bf->loc])
        fseek(bf->program, (long int)stack_peak(bf->func_ptr_stack), SEEK_SET);
    else
        stack_pop(bf->func_ptr_stack);
}

// TODO(): Implement parsing tree
bf_call_t bf_parse(char c) {
    switch (c) {
        case '!':
            return bf_exit;
        case '?':
            return bf_exit_error;
        case '"':
            return bf_comment;
        case '>':
            return bf_inc_loc;
        case '<':
            return bf_dec_loc;
        case '+':
            return bf_inc_mem;
        case '-':
            return bf_dec_mem;
        case ',':
            return bf_read_mem;
        case '.':
            return bf_write_mem;
        case 'r':
            return bf_read_char;
        case 'w':
            return bf_write_char;
        case '[':
            return bf_start_loop;
        case ']':
            return bf_end_loop;
        default:
            return bf_do_nothing;
    }
}