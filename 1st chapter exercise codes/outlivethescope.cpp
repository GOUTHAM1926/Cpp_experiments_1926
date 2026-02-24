#include "PPP.h"
int* foo() {
    int x = 10;          // local variable on stack
    int* p = new int[10]; // array on heap
    return p;             // we return pointer to heap array
} // 'x' is destroyed here, but heap array stays alive!

int main() {
    int* arr = foo();  // arr points to memory still valid
    // use arr here
    delete[] arr;      // free when done
}
/* The array created with new inside foo() stays alive after foo() returns.
    Why? Because it was created on the heap.
    The local variable x is destroyed when foo() returns.
    Why? Because it was created on the stack.
    The array created with new must be manually freed with delete[].
    Why? Because it was created with new.  */
// If we forget to call delete[], we have a memory leak.
// If we return &x from foo(), we have a dangling pointer.
// If we call delete[] arr in main(), then use arr afterwards, we have a dangling pointer.
// Dangling pointer: a pointer that points to memory that has been freed or is otherwise invalid.
// Dereferencing a dangling pointer is undefined behavior.
// Memory leak: memory that is no longer accessible but has not been freed.
// Memory leaks waste memory and can lead to program crashes if memory runs out.
// Avoid memory leaks by ensuring every new has a corresponding delete.
// Avoid dangling pointers by not using pointers after the memory they point to has been freed or gone out of scope.
// Dangling pointers and memory leaks are common sources of bugs in C++ programs.
// Always pair new with delete and new[] with delete[].
// Prefer smart pointers (like std::unique_ptr and std::shared_ptr) to manage dynamic memory automatically and avoid leaks and dangling pointers.
// Avoid returning pointers or references to local (stack) variables from functions.
// Local variables are destroyed when the function returns, so the pointer/reference would be invalid.
// Use heap allocation (with new) if you need to return a pointer/reference from a function, but remember to manage the memory properly.
// Alternatively, return by value or use smart pointers to avoid manual memory management.
