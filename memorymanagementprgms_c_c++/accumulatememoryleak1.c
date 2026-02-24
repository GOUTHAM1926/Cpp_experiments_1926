#include <stdlib.h>

int main() {
    for (int i = 0; i < 1000000; ++i) {
        malloc(1024); // every iteration leaks 1 KB -> process keeps growing
    }
    return 0;
}
/*heap: [..free..][ALLOC(100) - header + user 100 bytes][..free..]
you have no pointer to ALLOC(100) => cannot free it
Consequences

Memory is allocated and marked "in-use" in allocator bookkeeping.

Program has no way to call free() on that block -> memory leak.

In a short-lived program this leak is reclaimed by OS on exit; in long-running programs this leads to increasing memory usage and possible OOM.(out -of-memory leak )*/
//For that program, yes, <stdlib.h> is enough. You don't need <stdio.h> because you aren't using any input/output functions like printf() or scanf().
/*The Memory Leak

A memory leak occurs when a program allocates memory on the heap but fails to deallocate it before losing the reference to it.
 In this program, the loop repeatedly calls malloc(1024) but never calls free(), causing a memory leak.

    malloc(1024): This function allocates 1024 bytes (1 KB) of memory from the heap for each iteration of the loop.

    The void* pointer returned by malloc() is not stored anywhere. It's immediately lost. There is no way for the program to call free() on this memory later.

    This process is repeated 1,000,000 times.*/

    /*The Total Leaked Memory

The total amount of leaked memory is calculated by multiplying the number of allocations by the size of each allocation:

    Total Bytes: 1,000,000×1,024 bytes=1,024,000,000 bytes

    Total Kilobytes (KB): 1,024,000 KB

    Total Megabytes (MB): 1,000 MB

    Total Gigabytes (GB): 1 GB

This program will leak exactly 1 GB of memory.
 This will cause the process's memory footprint to grow continuously,
  which could lead to performance issues or even a crash if the system runs out of available memory.*/
  /*When a program terminates, the operating system reclaims all of the resources it had previously allocated to that process, including:

    The stack memory.

    Any memory that was still on the heap, including the leaked memory.

This automatic cleanup by the OS prevents a single program's leaks from affecting the entire system.
 However, this cleanup only happens when the program exits. 
 In a long-running program like a server, this kind of memory leak would be a critical problem.*/