#include <iostream>
#include <thread>
#include <chrono>
using namespace std;

int main() {
    cout << "Hello";             // goes to buffer
    this_thread::sleep_for(2s);  // waits 2 seconds
    cout << " World"<<endl;          // buffer flushes when newline appears (may not always)
}
