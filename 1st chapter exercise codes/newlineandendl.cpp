#include <iostream>
#include <thread>   // for sleep
#include <chrono>   // for seconds
using namespace std;

int main() {
    cout << "Using \\n: ";
    cout << "Hello\n";
    this_thread::sleep_for(2s);  // wait 2 seconds
    cout << "World\n";            // sometimes "Hello" appears immediately, sometimes delayed

    cout << "\nUsing endl: ";
    cout << "Hello" << endl;      // forces flush
    this_thread::sleep_for(2s);   // wait 2 seconds
    cout << "World" << endl;

    return 0;
}
// This program demonstrates the difference between using '\n' and 'endl' in C++ for output.
/*What You’ll See

First part (\n):

“Hello” may not appear immediately on some systems until the buffer flushes.

After 2 seconds, “World” appears.

Second part (endl):

“Hello” appears immediately, even before the 2-second wait.

Then “World” appears after 2 seconds.   
*/