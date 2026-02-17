#include <stdio.h>
#include <stdlib.h>
#include "skip_list.c"

int main() {
    Node* root = NULL;
    
    root = insert(root, 50);
    root = insert(root, 30);
    root = insert(root, 70);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 60);
    root = insert(root, 80);


    printf("Inorder traversal: ");
    inorder(root);
    printf("\n");

    int key = 40;
    Node* found = search(root, key);
    if (found)
        printf("Key %d found in the tree.\n", key);
    else
        printf("Key %d not found in the tree.\n", key);

    freeTree(root);
    return 0;
}
