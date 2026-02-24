#include "PPP.h"
void printEntry(const char* memory) {
    // Read the length from the first byte
    int length = *memory;
    cout<< "LENGTH OF THE STRING : "<<static_cast<int>(*memory) << "\n"; // Print the length of the current entry
    memory++; // Move to the first character

    // Print each character
    for (int i = 0; i < length; ++i) {
        std::cout << *memory;
        memory++; // Move to the next character
    }
    
    std::cout << std::endl;
}

int main() {
    // Simulated memory block
    const char memory[] = {
        3, 'j', 'i', 'm',
        3, 'b', 'o', 'b',
        3, 'd', 'e', 'b',
        5, 'c', 'a', 'r', 'o', 'l'
    };

    // Start at address 0
    const char* ptr = memory;

    // Print all entries
    
        while (ptr < memory + sizeof(memory)) {
    printEntry(ptr); // prints the string

    for (int i = 0; i <= *ptr; ++i) {
        std::cout << "Address: " << static_cast<const void*>(ptr + i)
                  << " Char: " << (i == 0 ? '-' : *(ptr + i))
                  << " | ASCII: " << static_cast<int>(*(ptr + i))
                  << std::endl;
    }

    ptr += (*ptr) + 1; // move to next entry
}


        

    return 0;
}

/* address = X
length = *address
address = address + 1
while length > 0 {
    print *address
    address = address + 1
    length = length - 1
} 
    */