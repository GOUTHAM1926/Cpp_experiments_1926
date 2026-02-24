//The Fixed Code (with Cleanup Function)


#include <stdio.h>
#include <stdlib.h>

char *cache = NULL; // Global pointer

// The correct way: Define a function to free the global cache.
void cleanup_cache(void) {
    if (cache != NULL) {
        printf("--- Running cleanup_cache ---\n");
        printf("Freeing memory at address: %p\n", (void*)cache);
        free(cache);
        cache = NULL; // Best practice: set the pointer to NULL after freeing.
    } else {
        printf("Cache is already empty, no need to free.\n");
    }
}

void add_to_cache_fixed(void) {
    // Correct practice: Free the old memory BEFORE overwriting the pointer.
    cleanup_cache();
    
    cache = (char*) malloc(100);
    if (cache == NULL) {
        printf("Failed to allocate memory.\n");
        return;
    }
    
    printf("Global pointer 'cache' at: %p\n", (void*)&cache);
    printf("It now points to heap memory at: %p\n", (void*)cache);
}

int main(void) {
    printf("--- Main function starting (Fixed) ---\n");
    
    add_to_cache_fixed(); // First allocation
    add_to_cache_fixed(); // Second allocation (the first one is freed correctly)
    
    printf("\n--- Program exiting ---\n");
    // Final cleanup: Call the cleanup function before the program ends.
    cleanup_cache();
    
    return 0;
}
/*The Global Pointer Itself

    The char *cache = NULL; declaration exists outside of any function. This means the cache pointer variable itself is global. It is allocated in the program's data segment and persists for the entire program's lifetime. Its address remains fixed.

2. The Function Calls from main()

    The main() function is the entry point of your program. Any code you want to execute must be called from main() or a function that main() calls.

    When you call add_to_cache_fixed(), the cache pointer is accessed and modified. 
    It's a global variable, so any function can access and change its value.
     The memory allocation happens on the heap, and its address is stored in the global cache pointer.

    When you call cleanup_cache(), that function also accesses the global cache pointer.
     It checks if it's NULL and, if not, it calls free() on the memory address stored in cache.

3. Why This Isn't a Local Cleanup

The cleanup isn't "local" because the cleanup_cache() function isn't just cleaning up its own local variables.
 It's working on a global variable (cache) that was defined outside of the function itself.

Think of it like this:

    The Global Variable: The cache pointer is like a shared notebook on a table.

    The Functions: The add_to_cache_fixed() and cleanup_cache() functions are like two different people who can sit down at the table and write in the notebook.

    The Call from main(): main() is the manager who tells these people when to work on the notebook.

Even though the people (add_to_cache_fixed() and cleanup_cache()) are working "locally" at the table, 
they are changing something that is globally accessible (the shared notebook). By having main() explicitly call cleanup_cache() at the end,
 you are ensuring that the shared resource is properly managed and not leaked before the program ends.

This is a fundamental pattern for managing global resources in C.
 You define the resource globally and then create dedicated functions to interact with it, ensuring that you manage its lifecycle from start to finish.*/