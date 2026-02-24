#include<iostream>
 class Employee {
    public:
    std::string name;
    std::string company;
    int age;
//std::string name,std::string company,int age
void introduce_employee(std::string name,std::string company,int age){
         Employee::name=name;
        Employee::company=company;
        Employee::age=age;
         std::cout<<"My name is " <<name<<" ,I work in "<<company<< " and my age is "<<age<<std::endl;
    }
    //by default ,compiler generates a default constructor,or else if you want a custom one , u can as shown in comments.
    //custom constructor
    // Employee(){}
    // Employee(std::string name1,std::string company1,int age1){
    //      name=name1;
    //     company=company1;
    //     age=age1;
    // }
};
    int main(){
        Employee employee1;
        employee1.introduce_employee("Gautam","BluBridge",23);
        //"Gautam","BluBridge",23
        employee1.introduce_employee("Sivani","IIIT-Bangalore",23);
        std::cout<<employee1.name;
    }
 /*#include<iostream>
 class Employee {
    public:
    std::string name;
    std::string company;
    int age;
//std::string name,std::string company,int age
void introduce_employee(std::string name,std::string company,int age){
        std::cout<<"My name is " <<name<<" ,I work in "<<company<< " and my age is "<<age<<std::endl;
         //Employee::name=name;
        // Employee::company=company;
        // Employee::age=age;
    }
};
    int main(){
        Employee employee1;
        employee1.introduce_employee("Gautam","BluBridge",23);
        //"Gautam","BluBridge",23
        std::cout<<employee1.name;
    }*/