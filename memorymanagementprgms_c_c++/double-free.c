#include <stdio.h>
#include <stdlib.h>

int main() {
    // 1. Allocate a block of memory on the heap.
    // This gives your program ownership of this memory.
    int* ptr = (int*)malloc(sizeof(int));

    if (ptr == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    *ptr = 100;

    printf("--- Before first free() ---\n");
    printf("Address of pointer on stack: %p\n", &ptr);
    printf("Value stored in pointer (heap address): %p\n", ptr);
    printf("Value at the heap address: %d\n", *ptr);

    // 2. Free the memory correctly the first time.
    // This returns the memory to the OS.
    printf("\n--- Calling free(ptr) the first time ---\n");
    free(ptr);
    printf("Memory is now freed.\n");

    // At this point, ptr is a dangling pointer.
    // It still holds the old address, but your program no longer owns it.

    printf("Address of pointer on stack (unchanged): %p\n", &ptr);
    printf("Value stored in pointer after first free: %p\n", ptr);
    // WARNING: Accessing *ptr here is a use-after-free bug and is UNDEFINED BEHAVIOR.
    // Do not do this in real code!

    // 3. Attempt to free the same memory block a second time.
    // This is the double-free bug.
    printf("\n--- Calling free(ptr) the second time (Double-Free Bug) ---\n");
    free(ptr); // CRASH LIKELY TO OCCUR HERE!

    printf("This line might not be printed if the program crashes.\n");

    return 0;
}

/*The Double-Free Bug Explained

A double-free bug is a serious memory management error that occurs when a program calls the free() function on the same memory block more than once. 
This corrupts the memory manager's internal data structures, leading to unpredictable behavior, program crashes, or even security vulnerabilities.

Consequences and Catastrophic Failures

The consequences of a double-free bug are far more severe than simply freeing a valid pointer. When you call free() for the first time, 
the memory is returned to the operating system's memory pool and marked as available. 
The second free() call on the same pointer is where the real damage happens. Here's what can go wrong:

    Heap Corruption: The memory manager uses a complex system (often a linked list) to track which memory blocks are free and available for future malloc() calls.
     When you call free() a second time on the same address, you are effectively telling the memory manager that a block it already knows is free is now free again. 
     This corrupts the list, causing the memory manager's internal state to become inconsistent.

    Unpredictable Crashes: With a corrupted heap, any subsequent memory allocation or deallocation (malloc() or free()) may crash the program. 
    The memory manager might try to access a null pointer, an invalid memory address, or a memory address that belongs to another process. 
    This causes a segmentation fault, which is a catastrophic failure that the operating system handles by immediately terminating the program. 
    The crash could happen immediately after the double-free or much later, making it difficult to debug.

    Security Vulnerabilities: This is one of the most dangerous aspects of a double-free bug. 
    An attacker can deliberately exploit this bug to gain control of a program. 
    By carefully choosing the data written to the freed memory, an attacker could manipulate the corrupted heap to overwrite function pointers or other critical data. 
    When a program then attempts to use that corrupted data, it could execute the attacker's malicious code. 
    This is why double-free bugs are a major security risk in C and C++ programming.  
    
    How to Prevent It

    Set the Pointer to NULL: The best practice after freeing a pointer is to immediately set it to NULL. 
    This way, any subsequent attempt to call free() on the same pointer will be harmless, as free(NULL) is a valid, no-op operation.
    In programming, a "no-op" (short for "no operation") is an instruction that tells a computer to do nothing.
     It's an instruction that executes without changing the state of the system or its memory, except for the program counter, which points to the next instruction.

    Encapsulate Memory Management: 
    Use smart pointers in C++ (std::unique_ptr or std::shared_ptr) or 
    implement a robust class or function in C that handles memory allocation and deallocation to prevent direct manual free() calls.*/

    /* output : detected the bug 
    It was stopped, which is a good thing. The error is the consequence.

The fact that the program was terminated with a clear error message is the best possible outcome for a double-free bug. 
Instead of silently corrupting your system's memory and crashing later on, the memory manager caught the problem immediately.

Here's a breakdown of what happened:

    Your Code's Mistake: You attempted to free() a memory address that was already freed.

    The OS's Memory Manager: It detected this illegal operation. It saw that you were trying to give back a block of memory it had already received.

    The Consequence: The memory manager chose to terminate the program immediately with an error rather than allowing it to continue with a corrupted heap. 
    This prevented further, more unpredictable damage.

So, while the program stopped, it did so because the bug triggered an error. The error is the consequence, not the absence of one.
It means that your system's memory management library (specifically the GNU C Library, or glibc,
 which uses a tcache for fast memory allocation) is smart enough to detect the double-free bug and report it as an error, 
preventing a full-blown catastrophic failure and making it easier for you to debug.*/