/* // Include necessary header files
#include <iostream>   // For input/output operations (cin, cout)
#include <string>     // For using the std::string class

using namespace std;  // To avoid writing std:: before cin, cout, string, etc.

int main() {
    // Declare variables to store the previous and current words
    string previous;  // Automatically initialized to "" (empty string)
    string current;   // Automatically initialized to "" (empty string)

    // Start reading words from the input (e.g., keyboard or file)
    // The loop continues as long as there are words to read
    while (cin >> current) {
        // Check if the current word is the same as the previous word
        if (previous == current) {
            // If they are the same, print the repeated word
            cout << "repeated word: " << current << '\n';
        }

        // Update 'previous' to the current word for the next iteration
        // This ensures that the next word will be compared to the current one
        previous = current;
    }

    // The program ends when there are no more words to read
    return 0;
}
    */
/* #include "PPP.h"
int main(){
    string previous;
    string current;
    while(cin>> current){
        if(previous == current){
            cout<<"repreated word: "<< current << "\n";
        }
        previous = current;
    }
    return 0;
}
    */
#include "PPP.h"
int main()
{
int number_of_words = 0;
string previous;
// previous word; initialized to ""
string current;
while (cin>>current) {
++number_of_words;
// increase word count
if (previous == current)
cout << "word number " << number_of_words << " repeated: " << current << '\n';
previous = current;
}
}