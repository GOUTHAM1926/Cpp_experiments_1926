#include <stdio.h>
#include <stdlib.h>

int main() {
    // try allocating a huge amount of memory
    void* space = malloc(1000000000000000ULL); // 1 petabyte!

    if (space == NULL) {
        printf("Memory allocation failed!\n");
        return 1; // exit with error
    }

    printf("Memory allocated successfully.\n");

    free(space);
    return 0;
}
/*Why This Fails
Allocating a huge amount of memory like 1 petabyte (1,000,000,000,000,000 bytes) is likely to fail for several reasons:
    Physical Limitations: Most computers do not have anywhere near that amount of RAM or swap space. 
    Even high-end servers typically have only a few terabytes of RAM, which is orders of magnitude less than a petabyte.

    Operating System Limits: Operating systems impose limits on how much memory a single process can allocate. 
    These limits are often much lower than the total physical memory available. For example, on a 64-bit system, 
    the theoretical limit is very high, but practical limits are often in the range of a few terabytes.

    Fragmentation: Even if the total amount of free memory is large enough, 
    it may be fragmented into smaller blocks that cannot satisfy a single large allocation request.

    Address Space Limits: On 32-bit systems, the maximum addressable memory space is typically 4GB, 
    which is far less than a petabyte. Even on 64-bit systems, practical limits are often lower due to various factors.

When malloc fails, it returns NULL to indicate that the requested memory could not be allocated. 
Always check the return value of malloc (or any memory allocation function) to ensure that the allocation was successful before using the allocated memory.
Attempting to use a NULL pointer will lead to undefined behavior and likely crash your program. */