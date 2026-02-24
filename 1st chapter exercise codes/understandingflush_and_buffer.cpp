#include <iostream>
#include <thread>   // for sleep
#include <chrono>   // for seconds
using namespace std;

int main() {
    cout << "Hello";       // goes into buffer (not shown yet)
    cout << flush;         // force flush immediately → "Hello" appears

    this_thread::sleep_for(2s);   // wait 2 seconds

    cout << " World\n";    // goes into buffer, then flushed automatically at newline
    return 0;
}
/*What Happens Step by Step

cout << "Hello";

Stored in buffer, not guaranteed to appear on screen yet.

cout << flush;

Forces buffer to flush → "Hello" appears immediately.

Program waits 2 seconds.

cout << " World\n";

" World\n" goes to buffer, then flushed (newline often triggers flush).*/