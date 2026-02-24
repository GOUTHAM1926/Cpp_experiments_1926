#include <stdio.h>
#include <stdlib.h>

int main(void) {
    // 1. Safe allocation.
    int *p = (int*)malloc(sizeof(int));
    
    // 2. The essential check.
    if (p == NULL) {
        // Handle the failure gracefully.
        printf("--- FIX: Allocation Failed ---\n");
        printf("Memory allocation failed. Exiting gracefully.\n");
        return 1; // Return an error code.
    }
    
    // 3. Use the pointer only after it's been checked.
    printf("--- FIX: Allocation Succeeded ---\n");
    printf("Pointer 'p' address on the stack: %p\n", (void*)&p);
    printf("Value stored in 'p' (heap address): %p\n", (void*)p);
    
    *p = 42;
    printf("Successfully wrote value %d to memory at %p\n", *p, (void*)p);
    
    // 4. Free the memory.
    free(p);
    
    return 0;
}
/*The Fix: Always Check malloc Result

This code is robust and will handle both success and failure cases gracefully. It will not crash if malloc fails.*/