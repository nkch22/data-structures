//
// Created by kurduli on 10/22/24.
//

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "stack.h"

struct stack_t {
    int *data;
    size_t size;
    size_t capacity;
};

stack stack_create_default() {
    stack ret;
    ret.capacity = 7;
    ret.data = malloc(sizeof(ret.data) * ret.capacity);
    ret.size = 0;
    return ret;
}

stack stack_create_with_capacity(size_t capacity) {
    stack ret;
    ret.capacity = capacity;
    ret.data = malloc(sizeof(ret.data) * ret.capacity);
    ret.size = 0;
    return ret;
}

bool stack_push(stack *stack, int item) {
    if (stack == NULL) return false;
    if (stack->size == stack->capacity) {
       stack->data = realloc(stack->data, stack->capacity * 2);
        stack->capacity *= 2;
    }
    stack->data[stack->size] = item;
    stack->size += 1;
    return true;
}

int stack_pop(stack *stack) {
    assert(stack->size > 0);
    int ret = stack->data[stack->size - 1];
    stack->size -= 1;
    return ret;
}

bool stack_is_empty(stack *stack) {
    return stack->size == 0;
}

void stack_dealloc(stack *stack) {
    free(stack->data);
    stack->capacity = 0;
    stack->size = 0;
}

void stack_print(stack *stack) {
    printf("[ ");
    for (size_t i = 0; i < stack->size; i++) {
        if (i == stack->size - 1) {
            printf("%d", stack->data[i]);

        } else {
            printf("%d, ", stack->data[i]);
        }
    }
    printf(" ]\n");
}
