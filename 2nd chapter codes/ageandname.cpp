#include "PPP.h"
int main(){
    cout<<"Enter your name and age \n";
    string first_name="???" ;
    double age=-1.0;
    cout<<"initial name : "<<first_name<<"\n";
    cin>>first_name>>age;
    
    cout<<"Hello,"<<first_name <<" (age : "<<age*12<<" months)!\n";
}