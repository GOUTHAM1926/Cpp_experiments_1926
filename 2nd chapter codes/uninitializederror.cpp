#include "PPP.h"
int main()
{
double x;
//double x=2;  //initialize with some value ex: x=2 
double y = x;
double z = 2.0+x;
//double z=2.0+x+y;
//cout << z << endl;
}
// we "forgot" to initialize: the value of x is undefined
// the value of y is undefined
// the meaning of + and the value of z are undefined
/*The -Wall compiler option (note the capital 'W') enables a comprehensive set of compiler warning messages in GCC, Clang, and similar compilers. Despite its name suggesting "all warnings," it actually enables a specific subset of common and important warnings rather than every possible warning the compiler can generate.

​
What It Enables

The -Wall flag activates warnings for:

    Uninitialized variables

    Unused variables and functions

    Implicit function declarations

    Missing return statements in non-void functions

    Comparison between signed and unsigned values

    Format string issues in printf/scanf

    Parentheses warnings for ambiguous expressions

    Switch statements with missing cases

    Type mismatches and conversions

Why Use It

Using -Wall is considered a best practice because it catches common programming errors at compile time before they become runtime bugs. It's especially valuable when debugging C++ and CUDA code, as it can identify issues like unused variables or uninitialized memory that could lead to undefined behavior.
​
g++ -Wall -o myprogram myprogram.cpp
nvcc -Xcompiler -Wall -o myprogram myprogram.cu
For even more comprehensive checking, developers often combine -Wall with -Wextra and -Wpedantic to enable additional warnings beyond the standard set. You can also use -Werror to treat all warnings as errors, forcing you to fix them before compilation succeeds.​
 Implement these  compiler options for this program with the commands :g++ uninitializederror.cpp -Wall -Werror  ---> to treat warnings as errors
  g++ uninitializederror.cpp -Wall  --> to get only warnings as mentioned above cases */