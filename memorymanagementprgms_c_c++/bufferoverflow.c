#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
    // 1. Allocate a small buffer of 16 bytes.
    char *space = (char*)malloc(16);
    if (!space) return 1;

    printf("--- Allocating Memory ---\n");
    printf("Pointer 'space' address (on the stack): %p\n", (void*)&space);
    printf("Heap address returned by malloc:          %p\n", (void*)space);

    // This is the string that will overflow the buffer.
    const char *long_string = "this string is longer than 16 bytes!";
    printf("Length of the string to copy:             %zu bytes\n", strlen(long_string) + 1);

    // 2. The dangerous overflow happens here.
    // The strcpy() function doesn't check the size of the destination buffer.
    // It will write past the 16-byte boundary.
    strcpy(space, long_string);

    printf("\n--- After the Overflow ---\n");
    printf("The original 16-byte buffer is at:        %p\n", (void*)space);

    // DANGER: We are now attempting to print memory that was NOT allocated to us.
    // This is undefined behavior. The string might look normal, but it has
    // corrupted the memory area right after the buffer.
    printf("Content of the corrupted buffer:          '%s'\n", space);
    
    // 3. The crash will likely happen here.
    // free() will try to read the corrupted allocator metadata to determine
    // the size of the block to free, leading to a segmentation fault.
    printf("\n--- Calling free(), expecting a crash ---\n");
    free(space);
    
    return 0;
}
/*When a buffer overflow corrupts the allocator's metadata, here's what happens:

The Process After Corruption

    Your Code Calls free(space): You tell the memory allocator you're finished with the memory block you got from malloc(16). The allocator now needs to prepare that block to be returned to the heap for future use.

    The Allocator Reads Corrupted Metadata: To free the memory, the allocator first looks at its hidden metadata. It expects to see the block's size and other management information. But because your buffer overflow scribbled over this data, the allocator reads a nonsensical value. For example, it might read 999999999 where it expected 16.

    The Allocator Becomes "Confused": This is where the unpredictable consequences begin. The allocator tries to execute its internal logic using the garbage data it just read. Its instructions are something like this:

        Step A: "The block size is X. Mark X bytes as free."

        Step B: "Find the next free block by following the pointer at Y."

    The Crash or Bad Behavior: Because X and Y are now garbage values, the allocator's next actions are unpredictable.

        Case 1: free crashes immediately. The allocator might try to free an insane number of bytes (999999999), or it might try to dereference a garbage pointer, causing a segmentation fault. The program crashes right then and there.

        Case 2: free corrupts another part of the heap. The allocator might get confused and mistakenly mark a completely different, unrelated block of memory as free, causing another part of your program's data to be silently destroyed. This is a particularly dangerous scenario because the bug goes unnoticed until that other part of the program tries to use its now-corrupted data.

        Case 3: malloc crashes later. The free call might complete without an immediate crash. But later, when your program calls malloc again, the allocator tries to read its internal list of free blocks. Since that list was corrupted, it might try to follow a garbage pointer and crash.

This makes the bug so hard to find. The overflow happens at one point in the code, the metadata becomes corrupted, but the crash might occur much later, in a completely different part of the code that seems unrelated. The crash is just a symptom of the initial buffer overflow.
.*/
/*The Allocator's Secret Bookkeeping

Think of your program's heap memory like a library with an invisible librarian. When you ask for memory with malloc(16), the librarian gives you a small, 16-byte section. However, the librarian also uses a small, hidden space next to your section to store information about it, like:

    The size of your block.

    The status of your block (whether it's free or in use).

    Pointers to other blocks that are available, to keep track of the library's empty space.

This is the allocator metadata. It's the librarian's secret notes that keep the whole system running smoothly.

The Overflow and the Crash

Now, when your code does this:
strcpy(space, "this string is longer than 16 bytes!");
It's like you're writing in the space the librarian gave you, but your pen keeps going and starts scribbling all over the librarian's notes.

    Your Write Operation: You're supposed to write 16 bytes, but you try to write 37 bytes.

    The Overflow: The extra 21 bytes "overflow" out of your allocated space and overwrite the librarian's notes (the metadata).

    The Unpredictable Crash: When you call free(space), you're telling the librarian, "Hey, I'm done with this section. Put it back." The librarian then looks at its notes to figure out how big your section is and where the next free spot is. But since its notes are now corrupted with your scribbles, it gets confused. It might try to deallocate the wrong amount of memory, try to merge your block with a non-existent one, or follow a bad pointer. This confusion causes a segmentation fault and crashes your program.

The worst part is that the crash might not happen right at the moment of the overflow. It might happen later, when a different part of the program calls free or malloc, and the allocator tries to use the corrupted notes. This makes it incredibly difficult to debug because the crash happens in a completely different part of the code from the actual bug.*/
/*The Fix

The solution is to never write past the end of your allocated memory. The safest way to do this is to use bounds-checked functions.

For example, strncpy takes a maximum number of bytes to copy. This prevents the overflow from happening in the first place, ensuring that the allocator's metadata remains untouched. While it's not perfect (you have to manually add a null terminator), it's far safer than using strcpy.

In modern C, functions like snprintf are even better, as they handle both string formatting and bounds checking, making them a much more reliable choice*/