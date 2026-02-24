/*In C, the %p format specifier is specifically designed to print pointer addresses. However, it requires a void* pointer argument. 
If you pass a different pointer type (like char* or int*), the compiler might give a warning. By casting the pointer to (void*)space, 
you're explicitly telling the compiler that you are passing a generic pointer type, which is what %p expects.
 This is a standard and necessary practice to avoid compiler warnings and ensure correct behavior across different systems.*/
#include <stdio.h>
#include <stdlib.h>

int main(void) {
    // A: Initial allocation of 100 bytes
    char *space = (char*)malloc(100);
    
    // Always check for allocation failure
    if (space == NULL) {
        printf("Initial memory allocation failed.\n");
        return 1;
    }

    printf("--- Initial State ---\n");
    printf("1. Allocated 100 bytes at address in heap: %p\n", (void*)space);
    printf("   'space' pointer's address on the stack: %p\n", (void*)&space);
    
    // Store some data in the first block
    for (int i = 0; i < 10; ++i) {
        space[i] = 'A' + i;
    }
    printf("   Data stored in first block: %c%c%c...\n", space[0], space[1], space[2]);
    printf("---------------------\n\n");

    // B: Reassign the pointer, allocating a new block and creating a leak
    printf("--- Reassigning the Pointer ---\n");
    char *leaked_space = space; // This temporary pointer shows what's leaked and if we dont store it in temporary pointer here,we will lose it forever.
    // Now 'leaked_space' points to the original 100-byte block
    printf("address of leaked memory block: %p\n",(void*)leaked_space);
    printf("address of leaked memory block pointer on stack : %p\n",(void*)&leaked_space);
    space = (char*)malloc(200);

    if (space == NULL) {
        printf("Second memory allocation failed.\n");
        // We still need to free the first block before exiting!
        free(leaked_space); // If I forget to free that 100-byte space here, it will be a memory leak if it stops here without allocating 200 bytes for the space pointer
        return 1;
    }

    printf("2. Reassigned 'space' to a new 200-byte block at: %p\n", (void*)space);
    printf("   'space' pointer's address on the stack: %p\n", (void*)&space);
    printf("   The original 100-byte block at %p is now LEAKED!\n", (void*)leaked_space);
    
    // Store some new data in the second block
    for (int i = 0; i < 10; ++i) {
        space[i] = 'B' + i;
    }
    printf("   Data stored in new block: %c%c%c...\n", space[0], space[1], space[2]);
    printf("---------------------\n\n");

    // C: Freeing only the last-allocated block
    printf("--- Final Cleanup ---\n");
    free(space); // This frees the 200-byte block,but that leaked_space (100 bytes) is still leaked.
    // If we want to free that leaked memory, we should call free(leaked_space); here before return 0;
    printf("3. The 200-byte block at %p has been freed.\n", (void*)space);
    printf("   The 100-byte block at %p remains leaked.\n", (void*)leaked_space);

    return 0;
}
/* So in either ways,
1) If I forget to free that 100-byte space here, it will be a memory leak if it stops without allocating 200 bytes for the space pointer returning NULL from malloc() due to failure.
2) If I  wont free(leaked_space); before return 0; 100 bytes memory will be leaked even if 200 bytes is freed successfully.
So ,while Reassigning the pointer,we should always keep a temporary pointer to the old memory block if we plan to free it later,
 or free it immediately before reassigning the pointer.*/