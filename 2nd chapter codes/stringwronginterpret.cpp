#include <iostream>
using namespace std;

int main() {
    // Test case 1: Your original (works by luck)
    int x = 120;
    cout << "Case 1 - x=120:" << endl;
    cout << "As string: '" << reinterpret_cast<const char*>(&x) << "'" << endl;
    
    // Test case 2: This will likely crash or print garbage
    int y = 0x61626364;  // 'abcd' in ASCII
    cout << "Case 2 - y='abcd':" << endl;
    cout << "As string: '" << reinterpret_cast<const char*>(&y) << "'" << endl;
    
    // Test case 3: Another dangerous example
    int z = 65;  // 'A' in ASCII
    cout << "Case 3 - z=65:" << endl;
    cout << "As string: '" << reinterpret_cast<const char*>(&z) << "'" << endl;
    
    return 0;
}