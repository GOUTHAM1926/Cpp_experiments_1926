#include "PPP.h"
int main(){
char c = 'x';
int i1 = c;
int i2 = c+1000;
double d = i2+7.3;
cout<<c<<"\n"<<i1<<"\n"<<i2<<"\n"<<d<<"\n";
}

// i1 gets the integer value of c
// i2 gets the integer value of c added to 1000
// d gets the floating-point value of i2 plus 7.3
/*Type Promotion in Python

You are correct that Python does not have the same kind of automatic type promotion (or "implicit conversion") between fundamental data types like C++ does, especially when it comes to characters and numbers.

    No char Type: Python does not have a separate char type. A single character is just a string of length 1 (e.g., 'x').

    No Implicit Conversion for Arithmetic: You cannot directly add a string and a number:
# C++: char c = 'x';
int i = c + 1000; (Works due to promotion)
# Python:
c = 'x'
i = c + 1000
# ERROR: TypeError: can only concatenate str (not "int") to str
Explicit Conversion Needed: To perform the C++ equivalent in Python, you must explicitly convert the character to its integer value using the built-in ord() function, 
which gives its Unicode code point (which is the same as its ASCII value for common characters like 'x'):
c = 'x'
i1 = ord(c)       # i1 gets 120
i2 = ord(c) + 1000 # i2 gets 1120
d = i2 + 7.3       # d gets 1127.3
Python still handles the addition of i2 (an int) and 7.3 (a float) correctly by converting the int to a float for the operation, 
but it requires the programmer to explicitly convert the character-string to an int first.*/