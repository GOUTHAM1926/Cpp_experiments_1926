/*snprintf is a much better and more modern solution than strncpy. It's a safer function because it guarantees that the output string is always null-terminated and it won't write beyond the specified buffer size.*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
    // 1. Allocate a small buffer of 16 bytes.
    char *space = (char*)malloc(16);
    if (!space) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    // This is the string that is too long for the buffer.
    const char *long_string = "this string is longer than 16 bytes!";

    // 2. The safe way to copy a string using snprintf.
    // The '16' specifies the maximum number of bytes to write to the buffer.
    // snprintf will automatically add a null terminator at the end,
    // as long as the size is greater than 0.
    snprintf(space, 16, "%s", long_string);

    printf("--- Safe Operation ---\n");
    printf("Pointer 'space' address (on the stack): %p\n", (void*)&space);
    printf("Heap address returned by malloc:          %p\n", (void*)space);
    printf("Content of the buffer:                    '%s'\n", space);
    
    // 3. The free() call now works as expected.
    // The allocator metadata was never corrupted.
    printf("\n--- Calling free() ---\n");
    free(space);
    printf("Memory freed successfully. No crash.\n");

    return 0;
}