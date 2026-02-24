#include "PPP.h"
void testStack() {
    int arr[5];   // stack
    arr[0] = 10;
    cout<<arr[0]<<"\n";          // prints 10   
} // arr is automatically destroyed here

void testHeap() {
    int* arr = new int[5];   // heap
    arr[0] = 10;
    cout << arr[0]<<"\n";          // prints 10
} // arr still exists! but we lost the pointer (memory leak!)
// we should have called delete[] arr; before losing the pointer
int main(){
    testStack();
    testHeap();
}