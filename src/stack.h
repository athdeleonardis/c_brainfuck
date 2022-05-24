#ifndef STACK
#define STACK

#include "linked_list.h"
#include "data.h"

typedef linked_list_t stack_t;

stack_t *stack_create(data_deleter_t, data_printer_t);
void stack_delete(stack_t*);
void stack_print(stack_t*);
void stack_push(stack_t*,data_t);
data_t stack_pop(stack_t*);
data_t stack_peak(stack_t*);

#endif
