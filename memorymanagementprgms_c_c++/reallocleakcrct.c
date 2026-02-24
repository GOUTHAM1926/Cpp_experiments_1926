#include <stdio.h>
#include <stdlib.h>

int main(void) {
    // === Step 1: Initial Allocation ===
    // Allocate 100 bytes and store the address in 'space'.
    char *space = (char*)malloc(100);
    if (!space) {
        printf("Initial allocation failed. Exiting.\n");
        return 1;
    }

    // Print the addresses to see the initial state of memory.
    printf("--- Initial Allocation ---\n");
    printf("Pointer 'space' address (on the stack): %p\n", (void*)&space);
    printf("Heap address stored in 'space':        %p\n", (void*)space);
    printf("Allocated size: 100 bytes\n\n");

    // ---
    // === Step 2: Safe Reallocation ===
    // We use a temporary pointer to safely handle realloc's return value.
    // If realloc fails, it returns NULL, but the original 'space' pointer is not lost.
    char *temp_ptr = (char*)realloc(space, 200);

    // Check if realloc succeeded.
    if (temp_ptr == NULL) {
        printf("--- Reallocation Failed ---\n");
        // The original 100-byte block is still at the same address.
        // We can now free it to prevent a memory leak.
        printf("Realloc returned NULL. The original block is still at %p.\n", (void*)space);
        printf("The program will now free the original block and exit.\n");
        free(space);
        return 1;
    }

    // ---
    // === Step 3: Success and Address Check ===
    // If we reach here, realloc succeeded. Now we check where the memory is.
    printf("--- Reallocation Succeeded ---\n");
    printf("New pointer returned by realloc: %p\n", (void*)temp_ptr);
    printf("Original 'space' pointer:      %p\n", (void*)space);

    // This check tells us if the block was moved.
    if (temp_ptr == space) {
        printf("Realloc resized the block in-place. Address is unchanged.\n");
        // The memory is still at the same address.
    } else {
        printf("Realloc moved the block to a new location.\n");
        // The original block at 'space' has been automatically freed by realloc.
        // Now 'space' is a dangling pointer, but we have the new address in 'temp_ptr'.
    }

    // ---
    // === Step 4: Finalize and Cleanup ===
    // Update our main pointer to the correct address.
    // We must do this to use the new memory and to free it later.
    space = temp_ptr;
    printf("\n--- Final State ---\n");
    printf("Updated 'space' pointer: %p\n", (void*)space);
    printf("Final block size: 200 bytes\n\n");

    // Free the final memory block.
    free(space);
    printf("Memory at %p has been successfully freed.\n", (void*)space);

    return 0;
}
/*On realloc, either the block grows in place or allocator allocates a new block and copies data,
 then frees the old block internally. If realloc fails you must preserve the old pointer.
*/
/*Why Not Just Use temp_ptr?

The temporary pointer (temp_ptr) is a safety measure. You're right that after a successful realloc that moves the block,
 the original space pointer is a dangling pointer and shouldn't be used.

The reason you don't just use temp_ptr for the rest of your program is for code clarity and consistency. Your program's logic is built around the space pointer.
 By reassigning space = temp_ptr;, you ensure that all subsequent code that relies on space is using the correct, updated pointer.
  It's a standard and safe programming pattern.
 Both space and temp_ptr are on the stack, and by assigning one to the other, they will indeed hold the same address.
 The realloc Danger Without a Temporary Pointer :
 The problem isn't when realloc succeeds; the problem is when realloc fails.If realloc(space, 200) fails, it returns a NULL pointer.
  When you assign this NULL back to space,
   you lose the address of the original 100-byte block. Since you no longer have a pointer to that block, you cannot free it, creating a memory leak.

That's why the temporary pointer is so important. It acts as a safety net. If realloc fails,
your temporary pointer will be NULL, but your original space pointer will still hold the address of the 100-byte block, allowing you to free it properly.*/