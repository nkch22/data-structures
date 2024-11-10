//
// Created by kurduli on 10/22/24.
//

#ifndef DYNAMIC_ARRAY_H
#define DYNAMIC_ARRAY_H

#include <stdbool.h>
#include <stdlib.h>

typedef struct dynamic_arr_t dynamic_arr;

dynamic_arr dynamic_arr_create_default();

dynamic_arr dynamic_arr_create_with_capacity(size_t capacity);

bool dynamic_arr_push(dynamic_arr *arr, int item);

int dynamic_arr_pop(dynamic_arr *arr);

bool dynamic_arr_insert(dynamic_arr *arr, int index, int item);

bool dynamic_arr_remove(dynamic_arr *arr, int index);

void dynamic_arr_dealloc(dynamic_arr *arr);

void dynamic_arr_print(dynamic_arr *arr);

#endif //DYNAMIC_ARRAY_H
