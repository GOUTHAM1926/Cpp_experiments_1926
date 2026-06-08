#include<iostream>
class Employee{
    public:
    std::string name;
    std::string company;
    int age;
    //custom constructor
    Employee(std::string name1,std::string company1,int age1){
name=name1 ;//can do like this too "Employee::name=name1;"
company=company1;
age=age1;
    }
void introduce_yourself(){
std::cout<<"My name is "<<name<<" ,Iam working in "<<company<<" and my age is "<<age<<std::endl;
};
};
int main(){
    //Employee employee1=Employee("Gautam","BluBridge",23);
    Employee employee1("Gautam","BluBridge",23);
    employee1.introduce_yourself();
}
