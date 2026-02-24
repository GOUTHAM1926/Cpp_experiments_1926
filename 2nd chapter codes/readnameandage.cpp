/*Get the “name and age” example to run. Then, modify it to write out the
age in number of months: read the input in years and multiply (using the *
operator) by 12. Read the age into a double to allow for children who can
be very proud of being five and a half years old rather than just five */
#include<iostream>
using namespace std;

int main(){
    cout << "Please enter your name and age\n";
string name = "???";
// string variable ("???" indicates "don’t know the name")
double age = -1;
// double(floating values) variable (-1 means "don’t know the age")
cin >> name >> age;
// read a string followed by an integer
cout << "Hello, " << name << " (age in months : " << age*12 << ")\n";
}
