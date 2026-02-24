#include "PPP.h"
/*#include <iostream>
using namespace std;
#include <string>*/
 int main()
 {int age = -1;
string name;
cin >> age; 
cin >> name; 
int a2 = age+2;
string n2 = name + " Jr. ";// + adds integers
// + concatenates strings
int a3 = age-2;
//string n3 = name -" Jr. "; // - subtracts integers
// error: - isn’t defined for strings
cout<<age<<name;
}