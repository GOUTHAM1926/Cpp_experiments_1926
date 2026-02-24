//Early return / exception-like path skipping free
#include <stdio.h>
#include <stdlib.h>

// This function demonstrates the memory leak.
int process_with_leak(int cond) {
    char *space = (char*)malloc(100);
    if (!space) {
        printf("Initial allocation failed.\n");
        return -1; // This exit path is correct
    }

    printf("--- Function entered. Allocated memory at: %p\n", (void*)space);
    printf("Pointer 'space' address on the stack: %p\n", (void*)&space);

    if (cond) {
        printf("--- Condition is true. Returning early. --- \n");
        // BUG: This returns without ever reaching the free() at the end.
        return 2;
    }
    
    printf("--- Condition is false. Reaching normal cleanup path. --- \n");
    // This is the only way to get here, so this works.
    free(space);
    
    return 0;
}

// This function uses goto to fix the memory leak.
int process_with_fix(int cond) {
    char *space =  (char*)malloc(100);
    if (!space) {
        printf("Initial allocation failed.\n");
        return -1;
    }

    printf("--- Function entered. Allocated memory at: %p\n", (void*)space);
    printf("Pointer 'space' address on the stack: %p\n", (void*)&space);

    if (cond) {
        printf("--- Condition is true. Jumping to cleanup. --- \n");
        goto cleanup;
    }
    
    printf("--- Condition is false. Reaching normal cleanup path. --- \n");
    
cleanup:
    // This is a single, centralized cleanup point.
    printf("--- Running cleanup. Freeing memory at: %p\n", (void*)space);
    free(space);
    
    return 0;
}

int main(void) {
    printf("--- Testing process_with_leak (with leak) ---\n");
    process_with_leak(1); // Set cond to 1 to trigger the leak
    
    printf("\n--- Testing process_with_fix (no leak) ---\n");
    process_with_fix(1); // Set cond to 1 to show the goto works
    
    return 0;
}
//one solution is to use goto to jump to a cleanup section before returning early.
//Another solution is to use smart pointers in C++ (like std::unique_ptr) that automatically free memory when they go out of scope, even if you return early from a function.