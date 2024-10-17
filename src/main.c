#include <stdio.h>
#include "linked-list.h"

static Node *head = NULL;

int main(void) {
    appendFront(&head, 22);
    appendFront(&head, 5552);
    appendBack(&head, 2231);
    appendBack(&head, 77);

    removeFirst(&head);
    removeLast(&head);

    appendAt(&head, 2, 52);

    removeAt(&head, 1);
    removeAt(&head, 1);
    removeAt(&head, 0);

    list_print(head);
}
