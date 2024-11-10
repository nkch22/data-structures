//
// Created by kurduli on 11/10/24.
//

#include "queue.h"

#include <stdlib.h>

#include "linked-list.h"

struct queue_t {
    linked_list *list;
};

queue *queue_create_default() {
    queue *queue = malloc(sizeof *queue);
    queue->list = list_create_default();
    return queue;
}

void queue_push(queue *queue, int data) {
    list_push_back(queue->list, data);
}

int queue_pop(queue *queue) {
    return list_pop_front(queue->list);
}

void queue_dealloc(queue *queue) {
    list_dealloc(queue->list);
    free(queue);
}

void queue_print(queue *queue) {
    list_print(queue->list);
}

