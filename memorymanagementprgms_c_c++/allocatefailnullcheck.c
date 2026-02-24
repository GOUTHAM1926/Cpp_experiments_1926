#include <stdio.h>
#include <stdlib.h>

int main(void) {
    // 1. The dangerous allocation.
    int *p = (int*) malloc(sizeof(int)); //  It might work fine most of the time, but if malloc fails (which returns NULL), the program will crash with a segmentation fault.

    // This is the bug. The code immediately tries to dereference a pointer
    // that might be NULL, leading to a crash.
    *p = 42;

    printf("--- MISTAKE: Unsafe Code ---\n");
    printf("Pointer 'p' address on the stack: %p\n", (void*)&p);
    printf("Value stored in 'p' (heap address): %p\n", (void*)p);
    
    // Attempting to print the value from the unverified pointer.
    // If 'p' is NULL, this will cause a segmentation fault.
    printf("Value at the heap address: %d\n", *p);
    
    // The program may or may not reach this line.
    free(p);
    
    return 0;
}
/*When the malloc call fails, it returns a NULL pointer. The code doesn't check for this NULL result and immediately tries to dereference the pointer with *p = 42;. This is a critical error.The Mistake: Not Checking malloc Result

It might work fine most of the time, but if malloc fails (which returns NULL), the program will crash with a segmentation fault./*
The Consequences

    Null Dereference: You are attempting to write to a memory address that is not valid. The address NULL (or 0x0) is intentionally a non-writable address.

    Segmentation Fault (Segfault): When your program tries to access this invalid memory location, the operating system's memory management unit detects it and sends a signal to your program. This causes a segmentation fault, and the program crashes immediately.

This bug is particularly dangerous because on a machine with plenty of memory, malloc may never fail, and the program will seem to work perfectly. However, on a system under heavy load or with very little memory, malloc can fail, and the program will crash unpredictably.

The Fix

The fix is to always check the result of malloc before using the pointer.*/