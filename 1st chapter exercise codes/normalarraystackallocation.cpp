#include "PPP.h"
int main(){
int arr[5];  // size known at compile-time (fixed size)
arr[0] = 10;
cout<<arr[0]<<"\n"<<arr[1]<<"\n" ; //stored in stack memory 
// prints 10 for arr[0] and garbage value for arr[1] as aar[0] is initialized but arr[1] is not initialized
}