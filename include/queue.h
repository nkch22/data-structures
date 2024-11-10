//
// Created by kurduli on 10/22/24.
//

#ifndef QUEUE_H
#define QUEUE_H

typedef struct queue_t queue;

queue *queue_create_default();

void queue_push(queue *queue, int item);

int queue_pop(queue *queue);

void queue_dealloc(queue *queue);

void queue_print(queue *queue);

#endif //QUEUE_H
