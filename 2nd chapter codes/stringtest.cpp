#include "PPP.h"
int main (){
    cout<<"Enter your first name and last name: ";
    string firstname;
    cin>>firstname;
    string lastname;
    cin>>lastname;
    if(firstname==lastname)
        cout<<"Hey! You have the same first name and last name!\n";
    
    if(firstname<lastname)
        cout<<firstname<<" is alphabetically before "<<lastname<<"\n";

 if (firstname>lastname)
    cout<<firstname<<" is alphabetically after "<<lastname<<"\n";
 
 string name = firstname +" "+lastname;
 cout<<"Your full name is: "<<name<<"\n";

}