#include "PPP.h"
int main(){
    cout<<"Enter the int values of n and b: ";
    int n;
    int b;
    cin>>b;
cin>>n;
cout<<boolalpha; //to print boolean values as true or false instead of 1 or 0
cout<<"n=="<<n
<<"\nn+1=="<<n+1
<<"\nthree times n=="<<3*n
<<"\ntwice n=="<<n+n
<<"\nnsquared=="<<n*n
<<"\nhalf of n=="<<n/2
<<"\nsquareroot of n=="<<sqrt(n)
<<"\nmodulo of n=="<<n%b
<<"\ndivision of n=="<<n/b

<<"\n"<<(n/b*b+n%b==n) //the expression n/b*b+n%b==n is a Boolean expression and must be enclosed in parentheses when outputting, and ensure the syntax for cout chains is correct.
<<"\n";
}
/*int main (){
    cout<<"Please enter a floating-point value :";
    double n=0;
    cin>>n;
    cout<<"n=="<<n 
    <<"\nn+1=="<<n+1
    <<"\nthree times n=="<<3*n
    <<"\ntwice n=="<<n+n
    <<"\nn squared=="<<n*n
    <<"\nhalf of n=="<<n/2
    <<"\nsquare root of n=="<<sqrt(n)
    <<'\n';}
    */
    /*cin >> n;
cout << "n == " << n
<< "\nn+1 == " << n+1
<< "\nthree times n == " << 3*n
<< "\ntwice n == " << n+n
<< "\nn squared == " << n*n<< "\nhalf of n == " << n/2
<< "\nsquare root of n == " << sqrt(n)
<< '\n';*/
