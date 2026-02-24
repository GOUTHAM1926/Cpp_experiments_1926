#include<iostream>
class Employee{
std::string name;
std::string company;
int age;

public:
void set_name(std::string name1){   //setter to set name
    name=name1;
}
std::string get_name(){   //getter to get name
    return name;
}
void set_company(std::string company1){   //setter to set company
    company=company1;
}
std::string get_company(){   //getter to get company
    return company;
}
void set_age(int age1){   //setter to set age
    // if(age1>18){
    //     age=age1;
    // }
    age=age1;
}
int get_age(){   //getter to get age
    return age;
}
void introduce_yourself(){
    std::cout<<" My name is "<<name<<" working in "<<company<< " and my age is "<<age<<"."<<std::endl;
}
};// No custom constructor,so default constructor will be arranged by compiler itself.
int main(){
Employee employee1;
//employee1.introduce_yourself(); if i run this line without setting the values,it will print garbage values  for int dtypes and  empty spaces for strings.
employee1.set_name("Gautam_Reddy");
employee1.set_company("BluBridge");
employee1.set_age(18);
employee1.introduce_yourself();
employee1.set_name("Sivani_Reddy");
employee1.set_company("IIIT_Bangalore");
employee1.set_age(18);
employee1.introduce_yourself();
}

/* Encapsulation with custom constructor
#include<iostream>
class Employee{
private:
std::string name;
std::string company;
int age;
public:
Employee(std::string name1,std::string company1,int age1){  //custom constructor
name=name1;
company=company1;
age=age1;
}
void set_name(std::string name1){   //setter to set name
name=name1;
}
std::string get_name(){   //getter to get name
return name;
}
void set_company(std::string company1){   //setter to set company
company=company1;
}
std::string get_company(){   //getter to get company
return company;
}
void set_age(int age1){   //setter to set age
age=age1;
}
int get_age(){   //getter to get age
return age;
}
void introduce_yourself(){ 
std::cout<<" My name is "<<name<<" working in "<<company<<" and my age is "<<age<<"."<<std::endl;
}
};
int main(){
Employee employee1("Gautam","BluBridge",23);
employee1.introduce_yourself();
employee1.set_name("Sivani_Reddy");
employee1.set_company("IIIT_Bangalore");
employee1.set_age(23);
employee1.introduce_yourself();
}
*/