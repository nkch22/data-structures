//
// Created by kurduli on 10/17/24.
//

#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <stdbool.h>
#include <stddef.h>

typedef struct linked_list_t linked_list;

linked_list *list_create_default();

void list_push_back(linked_list *list, int data);

void list_push_front(linked_list *list, int data);

int list_pop_back(linked_list *list);

int list_pop_front(linked_list *list);

int list_get_at(linked_list *list, size_t index);

bool list_remove_at(linked_list *list, size_t index);

bool list_insert(linked_list *list, size_t index, int data);

void list_print(linked_list *list);

size_t list_size(linked_list *list);

bool list_is_empty(linked_list *list);

void list_dealloc(linked_list *list);

#endif //LINKED_LIST_H
