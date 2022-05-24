#ifndef LINKED_LIST
#define LINKED_LIST

#include "data.h"

typedef struct linked_list_node {
    struct linked_list_node *next;
    data_t data;
} linked_list_node_t;

typedef struct linked_list {
    linked_list_node_t *head;
    linked_list_node_t *tail;
    unsigned int size;
    data_deleter_t data_delete;
    data_printer_t data_print;
} linked_list_t;

linked_list_t *linked_list_create(data_deleter_t, data_printer_t);
void linked_list_append(linked_list_t*, data_t);
void linked_list_push(linked_list_t *, data_t);
void linked_list_delete(linked_list_t*);
void linked_list_print(linked_list_t*);

#endif
