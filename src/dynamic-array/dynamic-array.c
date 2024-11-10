//
// Created by kurduli on 10/22/24.
//

#include "dynamic-array.h"

#include <stdio.h>
#include <assert.h>

struct dynamic_arr_t {
    int *data;
    size_t size;
    size_t capacity;
};

dynamic_arr dynamic_arr_create_default() {
    dynamic_arr ret;
    ret.capacity = 7;
    ret.data = malloc(sizeof(ret.data) * ret.capacity);
    ret.size = 0;
    return ret;
}

dynamic_arr dynamic_arr_create_with_capacity(size_t capacity) {
    dynamic_arr ret;
    ret.capacity = capacity;
    ret.data = malloc(sizeof(ret.data) * ret.capacity);
    ret.size = 0;
    return ret;
}

bool dynamic_arr_push(dynamic_arr *arr, int item) {
    if (arr == NULL) return false;
    if (arr->size == arr->capacity) {
       arr->data = realloc(arr->data, arr->capacity * 2);
        arr->capacity *= 2;
    }
    arr->data[arr->size] = item;
    arr->size += 1;
    return true;
}

int dynamic_arr_pop(dynamic_arr *arr) {
    assert(arr->size > 0);
    int ret = arr->data[arr->size - 1];
    arr->size -= 1;
    return ret;
}

bool dynamic_arr_insert(dynamic_arr *arr, int index, int item) {
    if (arr == NULL || arr->size < index) return false;
    if (arr->size == arr->capacity) {
        arr->data = realloc(arr->data, arr->capacity * 2);
        arr->capacity *= 2;
    }

    for (int i = arr->size; i > index; i--) {
        arr->data[i] = arr->data[i - 1];
    }
    arr->data[index] = item;
    arr->size += 1;
    return true;
}

bool dynamic_arr_remove(dynamic_arr *arr, int index) {
    if (arr == NULL || arr->size < index) return false;
    for (int i = index; i < arr->size - 1; i++) {
        arr->data[i] = arr->data[i + 1];
    }
    return true;
}

void dynamic_arr_dealloc(dynamic_arr *arr) {
    free(arr->data);
    arr->capacity = 0;
    arr->size = 0;
}

void dynamic_arr_print(dynamic_arr *arr) {
    printf("[ ");
    for (size_t i = 0; i < arr->size; i++) {
        if (i == arr->size - 1) {
            printf("%d", arr->data[i]);

        } else {
            printf("%d, ", arr->data[i]);
        }
    }
    printf(" ]\n");
}
