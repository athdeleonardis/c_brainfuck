#ifndef BF
#define BF

#include "stack.h"
#include <stdio.h>

//
// 'bf.h' Definitions
//

#define BF_MEMORY_SIZE 1028
#define BF_RUNNING 0
#define BF_CLOSED 1
#define BF_ERROR -1

typedef struct {
    FILE *program;
    stack_t *func_ptr_stack;
    int loc;
    int *mem;
    int exit_code;
    int in_comment;
} bf_t;

bf_t *bf_create(FILE *);
void bf_delete(bf_t *);
void bf_step(bf_t *);

#endif