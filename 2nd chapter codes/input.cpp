#include "utils.h"
/* This includes iostream, string, and "using namespace std"
Inside PPP.h (typical contents):
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
The difference between " " and < >:
#include <iostream>    // System/standard library headers (angle brackets)
#include "PPP.h"       // User-defined/local headers (quotes) 
< >: For standard library headers
" ": For your own header files or textbook-provided headers
*/
int main(){
    cout<< " Pls enter your first name (followed by 'enter') :\n";
    string first_name;  
    /*first_name is a variable of type string
This sets aside an area of memory for holding a string of characters and gives
it the name first_name:*/
    cin>> first_name; //read characters into first_name
    cout<< "Hello, " << first_name << "!\n" ;
    return 0;
}
    //cin.get(); //to keep the console window open

//Command to run in terminal : g++ input.cpp PPP.h and ./a.out   
//a.out is the default name of the executable file created by g++ compiler
//If u want to give a specific name to the executable file ,use -o option like this : g++ input.cpp PPP.h -o myexe
//Then run it like this : ./myexe
//If u want to compile and run in one command : g++ input.cpp PPP.h -o myexe && ./myexe