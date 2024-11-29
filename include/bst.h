//
// Created by kurduli on 11/10/24.
//

#ifndef BINARY_SEARCH_TREE_H
#define BINARY_SEARCH_TREE_H

#include <stdbool.h>
#include <stddef.h>

typedef struct bst_t bst;

bst *bst_create_default();

bool bst_search(bst *bst, int value);

void bst_insert(bst *bst, int data);

bool bst_remove(bst *bst, int data);

size_t bst_size(bst *bst);

void bst_dealloc(bst *bst);

// TODO implement me
void bst_print(bst *bst);


#endif //BINARY_SEARCH_TREE_H
