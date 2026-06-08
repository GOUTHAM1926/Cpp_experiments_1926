#include <iostream>
using namespace std;
class Employee{
    
    public:
    std::string name;
    std::string company;
    int age;
void introduce_empl(){
    
        std::cout<<"I am "<<name<< " working in "<< company<< " and my age is "<<age <<"."<<std::endl;
    }

};
int main() {
    Employee employee1;
    employee1.name="Gautam";
    //employee1.name="Gautam_Reddy"; I can modify the class attributes as i want ,as there is no encapsulation on these attributes(see "encapsulation_getters_and_setters.cpp" to get an understanding on encapsulation)
    employee1.age=23;
    employee1.company="BluBridge";
    employee1.introduce_empl();

    Employee employee2;
    employee2.name="Sivani";
    employee2.age=23;
    employee2.company="IIIT-Bangalore";
    employee2.introduce_empl();
};
//for each employee if we go on creating objects ,it will be hectic ,so check "employee_class_with_constructor.cpp" file to get to know how to create constructors easing this process.