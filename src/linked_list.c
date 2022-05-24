#include "linked_list.h"
#include "data.h"
#include <stdio.h>
#include <stdlib.h>

//
// Auxilliary Definitions
//

linked_list_node_t *linked_list_node_create(data_t data);
void linked_list_node_delete(linked_list_node_t *node, data_deleter_t data_delete);
void linked_list_node_print(linked_list_node_t *node, data_printer_t data_print);

//
// Auxilliary Implementations
//

linked_list_node_t *linked_list_node_create(data_t data) {
    linked_list_node_t *new_node = malloc(sizeof(linked_list_node_t));
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

void linked_list_node_delete(linked_list_node_t *node, data_deleter_t data_delete) {
    linked_list_node_t *next = node->next;
    if (data_delete != NULL)
        data_delete(node->data);
    free(node);
    if (next != NULL)
         linked_list_node_delete(next, data_delete);
}

void linked_list_node_print(linked_list_node_t *node, data_printer_t data_print) {
    data_print(node->data);
    if (node->next != NULL)
        linked_list_node_print(node->next, data_print);
}

//
// 'linked_list.h' Implementations
//

linked_list_t *linked_list_create(data_deleter_t data_delete, data_printer_t data_print) {
    linked_list_t *new_list = malloc(sizeof(linked_list_t));
    new_list->data_delete = data_delete;
    new_list->data_print = data_print;
    new_list->head = NULL;
    new_list->tail = NULL;
    new_list->size = 0;
    return new_list;
}

void linked_list_append(linked_list_t *list, data_t data) {
    linked_list_node_t *new_node = linked_list_node_create(data);

    if (list->size == 0)
        list->head = new_node;
    else
        list->tail->next = new_node;
    list->tail = new_node;
    ++list->size;
}

void linked_list_push(linked_list_t *list, data_t data) {
    linked_list_node_t *new_node = linked_list_node_create(data);

    if (list->size == 0)
        list->tail = new_node;
    new_node->next = list->head;
    list->head = new_node;
    ++list->size;
}

void linked_list_delete(linked_list_t *list) {
    if (list->size != 0)
        linked_list_node_delete(list->head, list->data_delete);
    free(list);
}

void linked_list_print(linked_list_t *list) {
    printf("linked list:\n");
    if (list->size != 0)
        linked_list_node_print(list->head, list->data_print);
    printf("\n");
}
