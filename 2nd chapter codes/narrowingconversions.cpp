#include "PPP.h"
int main()
{
double d = 0;
while (cin>>d) {
// repeat the statements below as long as we type in numbers
int i = d;
// try to squeeze a floating-point value into an integer value
 signed char c = i; //gives 232 for input 1000 as first 8 bits are considered and remaining bits are truncated ,read those gemini chats  in mentioned below links 
 //char c=i; -->by default ,its considered as signed char,so it gives -24 for input 1000
// try to squeeze an integer into a char
cout << "d==" << d <<"\n"
// the original double
<< " i=="<< i <<"\n"
// double converted to int
<< " c==" << c <<"\n"
// int value of char
<< " char(" << c << ")\n";
// the char
cout << " c_as_int==" << (int)c <<"\n"; // This would print 232 or -24(if signed) -->for input 1000

}
}
/*Try This
Run this program with a variety of inputs:
Small values (e.g., 2 and 3).
Large values (larger than 127, larger than 1000).
Negative values.
56, 89, and 128.
Non-integer values (e.g., 56.9 and 56.2).
You’ll find that many inputs produce “unreasonable” results when
converted. Basically, we are trying to put a gallon into a pint pot (about 4
liters into a 500ml glass).*/
/* refer this link (geminin chat) to understand whats happening above :https://docs.google.com/document/d/1YnEVCAiOpEHVVS80dKJKWYgh6raM0-Gsp4L1vlU2WDc/edit?usp=sharing
and this too :https://docs.google.com/document/d/163UpAazkmivd-jVPC7bJZ9a5RatlaITPpYVpWILBHZ8/edit?usp=sharing 
and this too : https://docs.google.com/document/d/1ocz3Pg3PmQZ7YpxwAxhESNLikGY0uOtWp6dNQ3SkSYE/edit?usp=sharing */