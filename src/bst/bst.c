//
// Created by kurduli on 11/15/24.
//

#include "bst.h"

#include <assert.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct binary_tree_node_t binary_tree_node;

struct binary_tree_node_t {
    int data;
    struct binary_tree_node_t *left;
    struct binary_tree_node_t *right;
};

struct bst_t {
    binary_tree_node *root;
    size_t size;
};

static binary_tree_node *create_node(int data) {
    binary_tree_node *ret = malloc(sizeof *ret);
    ret->left = NULL;
    ret->right = NULL;
    ret->data = data;
    return ret;
}

static binary_tree_node *get_parent_of_node_with_value(bst *bst, int value) {
    binary_tree_node *parent = bst->root;    
    while (parent) {
        if (parent->left && parent->left->data == value) break;
        if (parent->right && parent->right->data == value) break;
        if (parent->data > value) 
            parent = parent->right;
        else 
            parent = parent->left;
    }
    return parent;
}

bst *bst_create_default() {
    bst *tree = malloc(sizeof *tree);
    tree->root = NULL;
    tree->size = 0;
    return tree;
}

bool bst_search(bst *bst, int value) {
    if (bst->root == NULL) return false;
    binary_tree_node *current = bst->root;
    while (current) {
        if (current->data == value) break;
        if (current->data < value) {
            current = current->right;
        } else {
            current = current->left;
        }
    }
    return current != NULL;
}

// this function excludes duplicate elements for better search performance
void bst_insert(bst *bst, int data) {
    if (bst->root == NULL) {
        bst->root = create_node(data);
        bst->size += 1;
        return;
    }

    binary_tree_node *current = bst->root;
    while (1) {
        if (current->data == data) {
            // do not allow for duplicates
            return;
        }
        if (current->data < data) {
            if (current->right == NULL) {
                current->right = create_node(data);
                break;
            }
            current = current->right;
        } else {
            if (current->left == NULL) {
                current->left = create_node(data);
                break;
            }
            current = current->left;
        }
    }
    bst->size += 1;
}

// Actually here I've considered two different approaches:
//      1. Default one is to search a parent node of the target.
//      2. To search the target node, and instead of deletion of this node,
//          we just copy contents of right/left child of this node into the target and delete the copied node
//  There are pros and cons in each approaches, with the default approach the code gets a bit convoluted,
//      but it is faster then the second method, since we just swap pointers of the nodes, while in the second
//      approach we copy each field of the node.
//  So I decided to go with the default one, cuz the speed is my high priority as a library writter.
//  And the convoluted code will be hidden under clear interface for the lib user
//  
//  Ah crap, seems like my algorithm isn't deleting nodes in optimal way
//  TODO: rewrite me in the future
bool bst_remove(bst *bst, int data) {
    assert(bst != NULL && "Null bst pointers are invalid use bst_create_default()");
    if (bst->root == NULL) return false;

    if (bst->root->data == data) {
        binary_tree_node *target = bst->root;
        if (target->left && target->right) {
            // shift right node in place of target node
            bst->root = target->right;
            binary_tree_node *child_left_end = target->right->left;
            while (child_left_end && child_left_end->left)
                child_left_end = child_left_end->left;
            if (child_left_end)
                child_left_end->left = target->left;
            else
                target->right->left = target->left;

        }
        else if (target->left && !target->right) {
            // we shift the left child into target place
            bst->root = target->left;
        }
        else if (target->right && !target->left) {
            bst->root = target->right;
        }
        else {
            // left and right are NULLs
            bst->root = NULL;

        }
        free(target);
        bst->size -= 1;
        return true;
    }

    binary_tree_node *parent = get_parent_of_node_with_value(bst, data);
    if (!parent) return false;

    bool is_right = parent->data > data;
    binary_tree_node *target = is_right ? parent->right : parent->left;
    if (target->left && target->right) {
        // shift right node in place of target node
        if (is_right) {
            parent->right = target->right;
        }
        else {
            parent->left = target->right;
        }
        binary_tree_node *child_left_end = target->right->left;
        while (child_left_end && child_left_end->left)
            child_left_end = child_left_end->left;
        if (child_left_end)
            child_left_end->left = target->left;
        else
            target->right->left = target->left;

    }
    else if (target->left && !target->right) {
        // we shift the left child into target place
        if (is_right) {
            parent->right = target->left;
        }
        else {
            parent->left = target->left;
        }
    }
    else if (target->right && !target->left) {
        if (is_right) {
            parent->right = target->right;
        }
        else {
            parent->left = target->right;
        }
    }
    else {
        // left and right are NULLs
        if (is_right) {
            parent->right = NULL;
        }
        else {
            parent->left = NULL;
        }

    }
    free(target);
    bst->size -= 1;
    return true;
}

static void dealloc_subtree(binary_tree_node *subtree) {
    dealloc_subtree(subtree->left);
    dealloc_subtree(subtree->right);
    free(subtree);
}

// TODO: rewrite me using iterative approach instead of recursive
void bst_dealloc(bst *bst) {
    dealloc_subtree(bst->root); 
    bst->root = NULL;
    bst->size = 0;
}

// TODO finish me
void bst_print(bst *bst)
{

}


size_t bst_size(bst *bst) {
    return bst->size;
}
