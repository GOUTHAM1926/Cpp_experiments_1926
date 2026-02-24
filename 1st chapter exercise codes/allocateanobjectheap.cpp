#include "PPP.h"
class Student {
public:
    string name;
    Student(string n) { name = n; }
};
int main(){
Student* s = new Student("Alice");  
cout << s->name<<"\n";   // prints Alice
delete s;          // free memory
}