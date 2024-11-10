//
// Created by kurduli on 10/22/24.
//

#ifndef STACK_H
#define STACK_H
#include <stdbool.h>
#include <stddef.h>

typedef struct stack_t stack;

stack *stack_create_default();

stack *stack_create_with_capacity(size_t capacity);

bool stack_push(stack *stack, int item);

int stack_pop(stack *stack);

bool stack_is_empty(stack *stack);

void stack_dealloc(stack *stack);

void stack_print(stack *stack);

#endif //STACK_H
