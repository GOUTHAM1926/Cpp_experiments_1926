/*this is not a standard practice to define int as integer,
C++ already has int, so redefining it as integer can confuse other programmers.
#define integer int tells the preprocessor:
👉 “Every time you see the word integer, replace it with int before compiling.” 
but the best practice is to use c++ alias with "using" keyword to define integer as int 
Macros don’t respect C++ scope rules.

If another library also defines integer as something else, you’ll get conflicts or strange bugs.*/

#include <iostream>
using namespace std;
using integer=int;
integer main(){
    cout<<'Iam Gautam K !\n';
    return 0;
}

