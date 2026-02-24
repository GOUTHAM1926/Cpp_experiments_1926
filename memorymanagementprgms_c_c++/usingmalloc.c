
#include<stdlib.h>
#include<stdio.h>
int main(){
    void* space =malloc(100); // allocate 100 bytes of memory
    if (space != NULL) { 
    // always check if malloc succeeded
        printf("Memory allocated successfully at address : %p\n",space);
        printf("memory address of pointer on stack : %p\n",&space);
        /* else {
        printf("Memory allocation failed.\n");
    } */ 
  }

    if (space == NULL) {
        printf("Memory Allocation failed. \n");
        return 1; // exit if allocation failed
    }
    // --- Before freeing ---
    printf("--- BEFORE FREEING ---\n");
    // Print the address stored in the 'space' pointer
    printf("Address of the allocated block: %p\n", space);
    printf("memory address of pointer on stack : %p\n",&space);
    // We can't dereference a void* directly. Let's cast it to char* to access the first byte.
    char* first_byte = (char*)space;  // *first_byte dereferences a char*. A char is a single-byte integer type.
    // Print the initial value (garbage value) at the first byte
    printf("Initial garbage value at the first byte: %d\n", *first_byte);
    printf("Initial garbage value at the first byte: %c\n", *first_byte);
    *first_byte = 'A'; // Store a value in the first byte
    printf("Value at the first byte of the block: %c\n", *first_byte);
    printf("Value at the first byte of the block: %d\n", *first_byte);
    printf("Address of the first byte: %p\n", first_byte);
    // Iterate through all 100 bytes
    //before initialisation
    printf("Values of the 100 bytes:\n");
    for (int i = 0; i < 100; i++) {
        printf("Byte %d: %d\n", i, *(first_byte + i));
    }
    for (int i = 0; i < 100; i++) {
        // You can now access and manipulate each byte individually
        *(first_byte + i) = i; // Store a value in each byte
    }

    // Now, print the value of each byte
    //After initialisation
    printf("Values of the 100 bytes:\n");
    for (int i = 0; i < 100; i++) {
        printf("Byte %d: %d\n", i, *(first_byte + i));
    }

    // Free the allocated memory
    free(space);

    // --- After freeing ---
    printf("\n--- AFTER FREEING ---\n");
    // The pointer still exists and holds the same address
    printf("memory address of pointer on stack (dangling pointer) : %p\n",&space);
    printf("Address stored in 'space' after free: %p\n", space);
    
    // WARNING: This is now undefined behavior!(use-after-free)
    // The data at this address is no longer guaranteed to be valid.
    // The program might crash, or it might print garbage.
    // Don't do this in real code.
// Print the (garbage value) at the first byte
    printf("Attempting to access freed memory: %d\n", *first_byte);
    printf("Attempting to access freed memory: %c\n", *((char*)space));
    // Iterate through all 100 bytes
    printf("Values of the 100 bytes:\n");
    for (int i = 0; i < 100; i++) {
        printf("Byte %d: %d\n", i, *(first_byte + i));
    }
    for (int i = 0; i < 100; i++) {
        // You can now access and manipulate each byte individually
        *(first_byte + i) = i; // Store a value in each byte
    }

    // Now, print the value of each byte
    printf("Values of the 100 bytes:\n");
    for (int i = 0; i < 100; i++) {
        printf("Byte %d: %d\n", i, *(first_byte + i));
    }


    return 0;
    
}
/* malloc() is a function in the C standard library. It's not a command.

    What it is: malloc() stands for "memory allocation". Its purpose is to request a block of memory from the heap, which is a large, 
    shared pool of memory available to your program during runtime.

    Where it's defined: It's defined in the C standard library and declared in the <stdlib.h> header file.
     You must include this header file in your C program to use malloc().

    How to call it: You call malloc() just like any other function, passing it one argument: the number of bytes you want to allocate. 
    It then returns a void pointer (void*) to the start of the newly allocated memory block. If it fails, it returns a NULL pointer.*/
/*A segmentation fault occurs when your program tries to access a memory location that it doesn't have permission to use. After you free() a memory block,
 your program no longer has permission to access that memory.
  If you try to, 
  the operating system's memory protection unit detects this illegal access and 
  immediately stops your program to prevent further damage to other programs or the system itself.

How it Happens in Your Program

    Run 1: You run your program the first time. The OS gives you a memory block at address X. You write data to it. You then free(X). 
    The memory manager marks X as available, but the data is still there. 
    Your program can "get away" with reading that freed memory because the OS hasn't reassigned it yet. This is undefined behavior, but it appears to work.

    Run 2: You run your program again. This time, imagine your system is busy.
     The OS memory manager now takes the previously-freed memory block at address X and gives it to a different program 
     (or even another part of your own program that runs before the use-after-free code). This other program writes its own data to that address.

    The Crash: When your code reaches the line printf("Attempting to access freed memory: %d\n", *first_byte);, 
    it tries to read from address X. But that address is now owned by another process. 
    The moment your program tries to access it,
     the operating system sees that your program doesn't have the permissions for address X and immediately triggers a segmentation fault. 
     The result is a crash. Your program just stops.

This type of failure is "catastrophic" because it's unpredictable and unrecoverable. 
It's not a logical error that your program can handle with a simple if/else statement. 
It's a fatal error that the OS has to manage for you.*/
/*after you free memory, it is no longer owned by your program.
 Before you called free(), the memory belonged to your program because you explicitly requested it from the OS using malloc(). 
 Once you call free(), you are returning that ownership.

Ownership Before free()

When you call malloc(), your program sends a request to the operating system's memory manager. The OS finds a contiguous block of memory on the heap and, if successful, returns the starting address of that block. At this point, your program has a lease on that memory. You are the sole owner, and you can read from or write to that memory as you wish.

Ownership After free()

When you call free(space), you are essentially telling the OS, "I am done with this memory block at this address. You can have it back." The OS takes note that this memory is now available.

    The memory is not instantly erased. The data you wrote to it might still be there, but the OS is now free to allocate that memory to another program or a different part of your program.

    The pointer is now a dangling pointer. The space variable on the stack still holds the old address, but that address no longer points to memory that your program owns.

    Accessing it is undefined behavior. Any attempt to read from or write to that memory after it's freed is a severe programming error. It's a "use-after-free" bug. Your program might work one time and crash the next. You have no guarantee of what will happen.

In the output you provided, your program successfully wrote and read from the freed memory because the OS hadn't reallocated or overwritten it yet. But you cannot rely on this. It's like returning a book to a library and then going to the shelf and starting to write in it again. You might get away with it if no one else has checked out the book yet, but it's fundamentally wrong.
*/
/* When you call free(space), you are telling the operating system that your program is finished with that block of memory. The OS can then give that memory to another part of your program or to another program entirely.

By accessing it again, you are creating a serious bug known as use-after-free. This can lead to a variety of unpredictable and dangerous issues, including:

    Data corruption: Another part of your program or another program might be using that memory, and your write operation could corrupt their data.

    Crashes: If the OS has already reclaimed the memory, your attempt to access it will cause a segmentation fault, which will crash your program.

    Security vulnerabilities: In some cases, a use-after-free bug can be exploited by attackers to run malicious code.*/
    /*To be clear:

    After free(space), the pointer space becomes a dangling pointer.

    The memory it points to is no longer valid.

    Any attempt to access it is an error.*/
    
/*When you're dealing with freed memory, the correct format specifier to use is the one that matches the type you are casting to. The leftover bits themselves have no inherent meaning until you tell the compiler how to interpret them.

Here's the breakdown:

Before Initializing the Memory

printf("Initial garbage value at the first byte: %d\n", *first_byte);

    *first_byte dereferences a char*. A char is a single-byte integer type.

    %d is the format specifier for a signed decimal integer.

    This combination tells printf to read a single byte from the memory location and print its value as a number. This is a common way to see the raw, uninitialized "garbage value" as a number. You could also use %c to see if that byte corresponds to a printable character, but %d is often more informative for raw data.

After Initializing to 'A'

printf("Attempting to access freed memory: %c\n", *((char*)space));

    *((char*)space) dereferences a char*.

    %c is the format specifier for a single character.

    This combination tells printf to read a single byte from the memory location and print it as a character. Since you explicitly put the character 'A' there, this is the correct way to print it as a character.

What to Use After Freeing?

After you call free(space), the memory's contents are undefined. You could use either %c or %d (or any other format specifier) to attempt to print what's there.

The key is that the value is no longer guaranteed to be what you put there. The operating system might reuse that memory and fill it with new data, so a subsequent read could return anything.

To answer your question directly: The choice of %d or %c depends on how you want to interpret the random leftover bits. There is no "correct" specifier because the data itself is no longer predictable.

    Use %c if you want to see if the leftover byte corresponds to a human-readable character.

    Use %d if you want to see the raw numerical value of the leftover byte.

Since you initially stored the character 'A', using %c might still print 'A' (if the memory hasn't been overwritten yet), which can be misleading. Using %d is often a better way to see that the value is now meaningless.

Remember, attempting to access freed memory is undefined behavior and a serious programming error. You should never do it in real code.



When you use an int* pointer, it means the pointer is specifically designed to work with int data. Yes, on most modern systems (which are 32-bit or 64-bit), an int is 4 bytes (32 bits), so an int* will read or write 4 bytes at a time.

The key difference between int* and void* is that the int* has a size associated with it. This allows for pointer arithmetic, where adding 1 to the pointer's address moves it forward by the size of the data type it points to.

    void* is a generic pointer. The compiler doesn't know what it points to, so it doesn't know how many bytes to move. This is why you must cast a void* to a specific type (like (int*)) before you can dereference it or use pointer arithmetic on it.

    int* is a typed pointer. The compiler knows it points to an int (4 bytes), so when you do ptr + 1, the address is incremented by 4 bytes, pointing to the next int in a sequence.*/
    