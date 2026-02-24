#include "PPP.h"
int main(){
    cout<<"Enter first name and last name  : ";
    string first_name;
    string last_name;
    cin>>first_name>>last_name;
    string full_name = first_name + ""+last_name;
    cout<<"Hello "<< full_name<<"\n";
    return 0;

}