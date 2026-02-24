#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node {
    char *name;
    int id;
};

int main(void) {
    // Stage 1: Allocate a container on the heap.
    // 'n' is a pointer on the stack that will point to the Node struct on the heap.
    struct Node *n = (struct Node*)malloc(sizeof(struct Node));
    if (n == NULL) return 1;

    // Stage 2: Allocate memory for a member *inside* the container.
    // 'n->name' is a pointer that lives *on the heap* inside the struct.
    // It will point to a SEPARATE block of memory for the string.
    n->name = (char*)malloc(50);
    if (n->name == NULL) {
        free(n); // Free the container before we exit!
        return 1;
    }
    strcpy(n->name, "Alice");
    n->id = 123;

    printf("--- Current Memory State ---\n");
    printf("1. The struct container is at heap address:        %p\n", (void*)n);
    printf("2. The string 'Alice' is at heap address:         %p\n", (void*)n->name);

    // ====================================================================
    // DANGER! A MEMORY LEAK MISTAKE IS MADE BELOW 
    // ====================================================================

    // This is a common bug: we free the container first.
    // This is the **WRONG** order for freeing memory. correcr order is to free members first, then the container.
    // to do so ,add this line before free(n):
    // free(n->name);
    // This will free the string memory first, then we can free the container.
    free(n);

    // The bug: free(n) deallocates the Node struct container.
    // This makes the pointer n->name unreachable.
    // We have no way to get to the string memory now.
    
    printf("\n--- The Memory Leak ---\n");
    printf("The struct container at %p has been freed.\n", (void*)n);
    printf("The memory for the string 'Alice' at %p is now permanently leaked.\n", (void*)n->name);
    printf("Why? Because we freed the container first, losing the pointer to the string.\n");
    printf("The 'name' pointer was on the heap inside the struct, so it was lost when the struct was freed.\n");

    return 0;
}