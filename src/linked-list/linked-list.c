//
// Created by kurduli on 10/18/24.
//

#include "linked-list.h"

#include <stdio.h>
#include <stdlib.h>

Node* createNode(int data, Node *next) {
    Node *node = malloc(sizeof *node);
    node->data = data;
    node->next = next;
    return node;
}

void appendBack(Node **head, int data) {
    Node *last = createNode(data, NULL);
    if (*head == NULL) {
        *head = last;
        return;
    }

    Node *tmp = *head;
    while (tmp->next) tmp = tmp->next;
    tmp->next = last;
}
void appendFront(Node **head, int data) {
    *head = createNode(data, *head);
}

bool removeLast(Node **head) {
    if (*head == NULL) return false;
    if ((*head)->next == NULL) {
        free(*head);
        *head = NULL;
        return true;
    }

    Node *tmp = *head;
    while (tmp->next->next) tmp = tmp->next;
    free(tmp->next);
    tmp->next = NULL;
    return true;
}

bool removeFirst(Node **head) {
    if (*head == NULL) return false;
    Node *toRemove = *head;
    *head = (*head)->next;
    free(toRemove);
    return true;
}

bool removeAt(Node **head, size_t index) {
    if (index == 0) {
        return removeFirst(head);
    }

    Node *tmp = *head;
    for (size_t i = 0; i < index - 1 && tmp; i++, tmp = tmp->next)
        ;

    if (tmp == NULL || tmp->next == NULL) return false;

    Node *toDelete = tmp->next;
    tmp->next = toDelete->next;
    free(toDelete);
    return true;
}

bool appendAt(Node **head, size_t index, int data) {
    if (index == 0) {
        appendFront(head, data);
        return true;
    }

    Node *tmp = *head;
    for (size_t i = 0; i < index - 1 && tmp; i++, tmp = tmp->next)
        ;

    if (tmp == NULL) return false;

    tmp->next = createNode(data, tmp->next);
    return true;
}

size_t list_size(Node *head) {
    size_t size = 0;
    while (head) {
        size += 1;
        head = head->next;
    }
    return size;
}

void list_print(Node *head) {
    size_t index = 0;
    while(head) {
        printf("{%zu; %d} -> ", index, head->data);
        head = head->next;
        index += 1;
    }
    printf("NULL\n");
}
