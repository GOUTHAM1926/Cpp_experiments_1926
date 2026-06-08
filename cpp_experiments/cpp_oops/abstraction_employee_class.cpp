#include<iostream>
class Employee{
    std::string name;
    std::string company;
    int age;
    public:
    Employee(){
    };
    Employee(std::string name1,std::string company1,int age1){
        Employee::name=name1; //can even just do like name=name1
        company=company1;
        age=age1;    
    };
    void set_name(std::string name1){name=name1;} //setter
    std::string get_name(){return name;} //getter
void set_company(std::string company1){company=company1;} //setter
std::string get_company(){return company;} //getter
void set_age(int age1){age=age1;} //getter
int get_age(){return age;} //setter
void Introduce_Yourself(){
    std::cout<<"Iam "<<name<< " ,working in "<<company<<" ,and my age is "<<age<<std::endl;
}
};

int main(){
    Employee employee1("Gautam K","Blubridge",21);
    employee1.Introduce_Yourself();
    Employee employee2;
    employee2.set_name("Sivani L");
    employee2.set_company("IIIT-Bangalore");
    employee2.set_age(22);
    employee2.Introduce_Yourself();
}