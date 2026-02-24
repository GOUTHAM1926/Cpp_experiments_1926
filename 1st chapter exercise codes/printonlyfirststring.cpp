#include <iostream>

void printEntry(const char* memory) {
    int length = *memory;     // Read the length
    memory++;                 // Move to first character

    for (int i = 0; i < length; ++i) {
        std::cout << *memory; // Print character
        memory++;             // Move to next character
    }
    std::cout << std::endl;
}

int main() {
    const char memory[] = {
        3, 'j', 'i', 'm',
        3, 'b', 'o', 'b',
        3, 'd', 'e', 'b',
        5, 'c', 'a', 'r', 'o', 'l'
    };

    // Just print the first string
    printEntry(memory);

    return 0;
}
