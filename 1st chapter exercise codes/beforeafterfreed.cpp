#include <iostream>
using namespace std;

int main() {
    int* p = new int;   // p is on stack, *p is on heap // p created on stack, heap memory allocated
    *p = 42;  // heap has value 42

    cout << "Value stored: " << *p << endl;
    cout << "Address of pointer p (stack): " << &p << endl;
    cout << "Address stored in p (heap location): " << p << endl;

    // Free the memory
    delete p; // heap memory released, but p (stack var) still exists
// p still exists here, but it's dangling
    cout << "\nAfter delete:" << endl;
    cout << "Value stored: " << *p << endl; // Undefined behavior (dangling pointer) // may print 42 or garbage
    /* delete p; only frees the heap memory (*p).

The pointer p variable is still alive until the end of its scope.

If you don’t set p = nullptr;, it will still hold the old heap address → now it’s a dangling pointer.*/
    cout << "Address of pointer p (still on stack): " << &p << endl;
    cout << "Value of p (dangling pointer, still shows old heap address): " << p << endl;

    // To be safe, set p to nullptr
    p = nullptr;
    cout << "Value of p after setting to nullptr: " << p << endl;

    return 0;
}
// end of main → p destroyed automatically (stack cleaned up)
/*The pointer variable p

Lives on the stack.

It is created when execution enters its scope (here: inside main).

It is destroyed only when main finishes (or when the variable goes out of scope if it were inside another block).

Even after you delete p;, the pointer variable itself (p) still exists on the stack — it just holds a meaningless (dangling) address.
The heap memory *p

Created by new.

Freed by delete.

After delete, the memory belongs back to the system (or runtime memory manager).

Whatever value was there (42) might still physically remain in RAM for a while, but it is no longer yours to use → undefined behavior if accessed.
p (the pointer variable) stays valid until main ends.

The memory it pointed to (the heap int) is gone right after delete.*/