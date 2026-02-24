// test.cpp
#include "calculator.h"  // Only the declaration is included
 int test(){
    
    return add(5,7) ; // Calls the same function defined in calculator.cpp
}
int main(){
    cout<<test()<<"\n";
    
}