#include "PPP.h"
int main(){
int a,b;
cout<< " Enter two positive integers : ";
cin >>a>>b;
int quotient = a/b; // Integer Division
int remainder = a%b; //Modulo Division(Remainder)

cout<< a<<"/"<<b<<"="<< quotient<< "\n";
cout<< a<<"%"<<b<<"="<< remainder<<"\n";
//To verify the relationship : a/b*b + a%b == a 
if(int (quotient*b + remainder) == a){
    cout<< "a/b*b + a%b ==a"<< "\n";

return 0;
}
}