#include <iostream>
#include <vector>
#include <memory> // Include the header for smart pointers

int process_with_smart_pointer(bool cond) {
    // std::make_unique handles the 'new' call and returns a unique_ptr.
    auto my_vector = std::make_unique<std::vector<int>>(10, 5);

    // No need to check for failure, as 'new' would throw an exception.
    
    // To get the raw pointer's address for printing, use the .get() method.
    std::cout << "Smart pointer created. The vector is at: " << my_vector.get() << std::endl;

    if (cond) {
        // Safe early return.
        // The 'my_vector' object is destroyed as the function exits,
        // which automatically frees the memory it owns. No leak.
        return 2;
    }

    std::cout << "Normal exit. Memory will be freed automatically." << std::endl;
    // The smart pointer is automatically destroyed here, freeing the memory.
    
    return 0;
}

int main() {
    std::cout << "--- Testing with smart pointer (no leak) ---\n";
    process_with_smart_pointer(true); // Early return, but no leak.
    
    std::cout << "\n\n--- Testing with smart pointer (no leak) ---\n";
    process_with_smart_pointer(false); // Normal exit, still no leak.
    
    return 0;
}
/* When a function with a smart pointer returns early, the smart pointer object's scope is completed, and it is automatically destroyed. Because a smart pointer's lifetime is tied to the memory it manages, the memory is also automatically freed, preventing a memory leak. This happens because the smart pointer's destructor is called when the object goes out of scope, and the destructor contains the code to free the memory.

Let's clarify one point: the function's scope is what completes. The function itself ceases to exist on the call stack when it returns. The smart pointer and the memory it manages are tied to the function's scope, so they are both cleaned up.

Why This Works

    RAII (Resource Acquisition Is Initialization): This is the core principle. A smart pointer object acquires a resource (memory on the heap) in its constructor and releases that resource in its destructor.

    Destructor Lifetime: In C++, an object's destructor is guaranteed to be called when the object's lifetime ends. This happens regardless of how the object goes out of scope, whether through a normal function exit, an early return statement, or even an exception.

    Automatic Cleanup: Because the destructor is called, the memory is freed automatically. This makes your code safer and eliminates the need for manual delete calls or complex goto logic.*/