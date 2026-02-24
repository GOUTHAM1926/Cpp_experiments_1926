#include <stdio.h>
#include <stdlib.h>

int main(void) {
    // === Step 1: Initial Allocation ===
    // Allocate 100 bytes of memory.
    char *space =(char*) malloc(100);
    if (!space) {
        printf("Initial allocation failed. Exiting.\n");
        return 1;
    }

    printf("--- Initial State ---\n");
    printf("Pointer 'space' address on the stack: %p\n", (void*)&space);
    printf("Heap address stored in 'space':        %p\n", (void*)space);
    printf("Allocated size: 100 bytes\n\n");

    // === Step 2: The Dangerous Reallocation ===
    // We attempt to reallocate to an astronomically large size (4 Petabytes)
    // to force a failure.
    printf("--- Attempting Dangerous Reallocation ---\n");
    printf("Attempting to resize block to 4 Petabytes (4000000000000000ULL bytes).\n");
    // This line is the bug: if realloc fails, 'space' is overwritten with NULL.
    space = (char*)realloc(space, 4000000000000000ULL); // This will almost certainly fail

    // === Step 3: Failure and Memory Leak ===
    // This 'if' block shows the result of the bug.
    if (space == NULL) {
        printf("--- Reallocation FAILED ---\n");
        printf("Realloc returned NULL.\n");
        printf("Original 'space' pointer's address on the stack is still the same: %p\n", (void*)&space);
        
        // This is where the memory leak happens. The address of the original
        // 100-byte block is now lost because the 'space' pointer was overwritten.
        printf("Heap address stored in 'space' is now: %p (NULL)\n", (void*)space);
        printf("The original 100-byte block is now a permanent memory leak.\n");
        
        return 1;
    }

    // This code would only run if realloc somehow succeeded.
    printf("--- Reallocation Succeeded (UNLIKELY) ---\n");
    printf("New pointer address: %p\n", (void*)space);
    
    // Final cleanup.
    free(space);

    return 0;
}