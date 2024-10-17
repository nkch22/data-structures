//
// Created by kurduli on 10/17/24.
//

#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <stdbool.h>
#include <stddef.h>

typedef struct Node_t {
    int data;
    struct Node_t *next;
} Node;

Node* createNode(int data, Node *next);

void appendBack(Node **head, int data);

void appendFront(Node **head, int data);

bool removeLast(Node **head);

bool removeFirst(Node **head);

bool removeAt(Node **head, size_t index);

bool appendAt(Node **head, size_t index, int data);

size_t list_size(Node *head);

void list_print(Node *head);

#endif //LINKED_LIST_H
