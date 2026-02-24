#include<iostream>
using namespace std;
#include<string>
int main()
{
string s= "Goodbye, cruel world! ";
int string =7; 
/*You can use names of facilities in the standard library, such as string for your
own variables, but you shouldn’t. Reuse of such a common name will cause
trouble if you should ever want to use the standard library*/
cout << s <<  string <<'\n';
return 0;
}