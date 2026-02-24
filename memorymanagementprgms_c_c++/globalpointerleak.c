#include <stdio.h>
#include <stdlib.h>

char *cache = NULL; // This is a global pointer, living in the data segment.

void add_to_cache(void) {
    printf("--- In add_to_cache function ---\n");
    // Leak scenario: If 'cache' already holds an address, that memory is lost.
    if (cache != NULL) {
        printf("!! WARNING: Previous cache memory at %p is now lost!\n", (void*)cache);
    }
    
    // Allocate 100 bytes on the heap.
    cache = (char*)malloc(100);
    
    // Check for allocation failure.
    if (cache == NULL) {
        printf("Failed to allocate memory.\n");
        return;
    }
    
    printf("Global pointer 'cache' is at address:      %p\n", (void*)&cache);
    printf("It now points to heap memory at address: %p\n", (void*)cache);
}

int main(void) {
    printf("--- Main function starting ---\n");
    
    add_to_cache(); // First allocation
    
    // Call it again to demonstrate the leak accumulation
    add_to_cache(); // Second allocation, leaks the first 100-byte block.
    
    printf("\n--- Program exiting ---\n");
    // The program terminates without freeing the last allocated block.
    printf("The final cache memory block at %p is leaked.\n", (void*)cache);
    
    return 0;
}
/* declaring a variable globally means you declare it outside of any function.

This gives the variable a global scope and a static lifetime.
 It means the variable exists for the entire duration of the program's execution and can be accessed from any function within the same file.
 This is different from local variables, which are declared inside a function and only exist as long as that function is running.*/
 /*What Happens in Memory

Imagine your program's memory is divided into a few key areas: the stack, the heap, and the data segment.

    Data Segment: This is where global variables live. The *cache pointer is here. This memory is allocated once at the very start of the program and is only released when the program completely shuts down.

    Heap: This is where memory you allocate with malloc lives. The 100-byte block that *cache points to is here. The heap is dynamic, meaning you can allocate and free memory from it as needed.

    Stack: This is for local variables and function calls. It's where the main() function's local variables would be stored, but since *cache is global, it's not on the stack.

When you run cache = malloc(100);, the following happens:

    The malloc function finds a free spot on the heap and allocates 100 bytes. Let's say it's at address 0x1000.

    The malloc function returns this address 0x1000.

    The global cache pointer, which is located in the data segment, has its value set to 0x1000. It now points to the heap.

/*The Scope Rule

    Local Allocation: If you call malloc() inside a function, you must call free() on that pointer inside the same function or pass it to another function 
    that will eventually call free().

    Global Allocation: If a global pointer is used to hold the malloc-ed memory, the free() call must also be handled globally.
     The best practice is to create a dedicated cleanup function that frees the memory and then call that function from main() just before the program ends. */