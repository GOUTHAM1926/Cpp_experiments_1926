#include "PPP.h"

using namespace std;
void reverse_dig(int &a, uint &b) {
    // Add your code here.
int rev_a=0,rev_b=0;
while(a>0){
    rev_a=(rev_a)*10+a%10;
    a/=10;
}
a=rev_a;
cout<<a<<endl;
while(b>0){
    rev_b=(rev_b)*10+b%10;
    b/=10;
    b=rev_b;
cout<<b<<endl;
}
cout<<b<<endl;
}
void swap(int &a, int &b) {
    // Add your code here.
    // int x;
    // x=a;
    // a=b;
    // b=x;
    
    a=a+b;
    b=a-b;
    a=a-b;
}
int main(){
    int x=1234;
uint y=3254;
    reverse_dig(x,y);

}