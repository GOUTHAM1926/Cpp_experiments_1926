#include "PPP.h"
int main(){
int* p = new int;   // allocates memory for 1 int
*p = 42;            // store value in that memory
cout << *p<<"\n";         // prints 42
delete p;           // free memory
}