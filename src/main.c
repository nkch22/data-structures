#include <stdio.h>
#include <bst.h>

int main(void) {
    bst *tree = bst_create_default();
    bst_insert(tree, 22);
    bst_insert(tree, 12);
    bst_insert(tree, 312);
    printf("%zu\n", bst_size(tree));
    printf("%d\n", bst_search(tree, 55));
    printf("%d\n", bst_search(tree, 12));
    printf("%d\n", bst_search(tree, 22));

    
    printf("remove %d\n", bst_remove(tree, 300));
    printf("remove %d\n", bst_remove(tree, 22));
    printf("%zu\n", bst_size(tree));

    bst_dealloc(tree);
    return 0;
}
