//
// Created by kurduli on 10/18/24.
//

#include "linked-list.h"

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct node_t {
    int data;
    struct node_t *next;
} node;

struct linked_list_t {
    node *head;
    node *tail;
    size_t size;
};

static node *create_node(int data, node *next) {
    node *node = malloc(sizeof *node);
    node->data = data;
    node->next = next;
    return node;
}

linked_list *list_create_default() {
    linked_list *list = malloc(sizeof *list);
    list->head = NULL;
    list->tail = NULL;
    list->size = 0;
    return list;
}

void list_push_back(linked_list *list, int data) {
    node *last = create_node(data, NULL);
    // empty list
    if (list->tail == NULL) {
        list->head = last;
        list->tail = last;
    }
    // single element
    else if (list->head == list->tail) {
        list->tail = last;
        list->head->next = list->tail;
    } else {
        // just append the element in the end
        list->tail->next = last;
        list->tail = list->tail->next;
    }
    list->size += 1;
}

void list_push_front(linked_list *list, int data) {
    assert(list != NULL);
    list->head = create_node(data, list->head);
    // empty list case
    if (list->tail == NULL) {
        list->tail = list->head;
    }
    list->size += 1;
}

// ATTENTION!
// undefined behaviour if you try to pop from empty list
int list_pop_back(linked_list *list) {
    assert(list->size > 0 && "list shouldn't be empty");
    int ret;
    if (list->size == 1) {
        ret = list->head->data;
        free(list->head);
        list->head = NULL;
        list->tail = NULL;
    } else {
        node *tmp = list->head;
        while (tmp->next != list->tail)
            tmp = tmp->next;
        ret = list->tail->data;
        free(list->tail);
        tmp->next = NULL;
        list->tail = tmp;
    }
    list->size -= 1;
    return ret;
}

// ATTENTION!
// undefined behaviour if you try to pop from empty list
int list_pop_front(linked_list *list) {
    assert(list->size > 0 && "list shouldn't be empty");
    int ret = list->head->data;
    node *to_remove = list->head;
    list->head = list->head->next;
    free(to_remove);
    list->size -= 1;
    return ret;
}

//
// ATTENTION!
// undefined behaviour if the index is greater or equal to the list size
int list_get_at(linked_list *list, size_t index) {
    assert(list->size > index && "index should be less than list size");
    node *tmp = list->head;
    while (index && tmp) {
        tmp = tmp->next;
        index -= 1;
    }
    return tmp->data;
}

// index in params is zero based
bool list_remove_at(linked_list *list, size_t index) {
    if (list->size == 0) return false;
    if (index == 0) {
        return list_pop_front(list);
    }
    node *tmp = list->head;
    for (size_t i = 0; i < index - 1 && tmp; i++, tmp = tmp->next);

    if (tmp == NULL || tmp->next == NULL) return false;

    node *to_remove = tmp->next;
    tmp->next = to_remove->next;
    free(to_remove);
    list->size -= 1;
    return true;
}

bool list_insert(linked_list *list, size_t index, int data) {
    if (index == 0) {
        list_push_front(list, data);
        return true;
    }

    // TODO: what if we also consider tail pointer
    // depending on the index param value
    node *tmp = list->head;
    for (size_t i = 0; i < index - 1 && tmp; i++, tmp = tmp->next);

    if (tmp == NULL) return false;

    tmp->next = create_node(data, tmp->next);
    list->size += 1;
    return true;
}

void list_print(linked_list *list) {
    size_t index = 0;
    node *tmp = list->head;
    while (tmp) {
        printf("{%zu; %d} -> ", index, tmp->data);
        tmp = tmp->next;
        index += 1;
    }
    printf("NULL\n");
}

size_t list_size(linked_list *list) {
    return list->size;
}

bool list_is_empty(linked_list *list) {
    return list->size == 0;
}

void list_dealloc(linked_list *list) {
    node *current = list->head;
    while (current) {
        node *next = current->next;
        free(current);
        current = next;
    }
    list->head = NULL;
    list->tail = NULL;
    list->size = 0;
    free(list);
}
