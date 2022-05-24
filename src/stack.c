#include "stack.h"
#include "linked_list.h"
#include "data.h"
#include <stdlib.h>
#include <stdio.h>

stack_t *stack_create(data_deleter_t data_delete, data_printer_t data_print) {
    return linked_list_create(data_delete, data_print);
}

void stack_delete(stack_t *stack) {
    linked_list_delete(stack);
}

void stack_print(stack_t *stack) {
    linked_list_print(stack);
}

void stack_push(stack_t *stack, data_t data) {
    linked_list_push(stack, data);
}

data_t stack_pop(stack_t *stack) {
    --stack->size;
    linked_list_node_t *node = stack->head;
    stack->head = stack->head->next;
    data_t data = node->data;
    free(node);
    return data;
}

data_t stack_peak(stack_t *stack) {
    return stack->head->data;
}
