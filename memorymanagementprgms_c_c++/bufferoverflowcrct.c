/*The correct solution is to prevent the buffer overflow from happening in the first place. Instead of using the unsafe strcpy function, you should use a function that performs a bounds check and won't write past the end of the allocated memory.

The Correct Solution: Using strncpy

This code uses strncpy, which is a safer alternative to strcpy. It prevents the buffer overflow and avoids corrupting the allocator's metadata, ensuring that the free call works correctly.*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
    // 1. Allocate a small buffer of 16 bytes.
    char *space =(char*) malloc(16);
    if (!space) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    // 2. The safe way to copy a string.
    // We use strncpy to copy at most 15 characters, leaving room for the null terminator.
    const char *long_string = "this string is longer than 16 bytes!";
    strncpy(space, long_string, 15);

    // 3. Manually add the null terminator.
    // strncpy does not automatically add a null terminator if the source string is too long.
    space[15] = '\0'; 

    printf("--- Safe Operation ---\n");
    printf("Pointer 'space' address (on the stack): %p\n", (void*)&space);
    printf("Heap address returned by malloc:          %p\n", (void*)space);
    printf("Content of the buffer:                    '%s'\n", space);
    
    // 4. The free() call now works as expected.
    printf("\n--- Calling free() ---\n");
    free(space);
    printf("Memory freed successfully. No crash.\n");

    return 0;
}