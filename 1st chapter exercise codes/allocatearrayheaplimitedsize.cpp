#include "PPP.h"
int main(){
int* arr = new int[5];   // allocate space for 5 integers
arr[0] = 10;
arr[1] = 20;
cout << arr[1]<<"\n";          // prints 20
delete[] arr;            // free memory for the array
}
/* Memory is created on the heap (even if size is known).

The array stays alive until you manually free it with delete[].

Why? Because new always means heap allocation, regardless of size.  */