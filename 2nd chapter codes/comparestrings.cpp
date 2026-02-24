#include "PPP.h"
int main(){
    cout<<"Enter two names(followed by 'enter') : \n";
    string name1;
    cin>>name1;
    string name2;
    cin>>name2;
    if (name1==name2){
        cout<<"You have entered the same name twice\n";}
    if(name1>name2){
        cout<< name1<<" is alphabetically after "<< name2<<"\n";
    }
    if(name1<name2){
        cout<<name1<<" is alphabetically before "<< name2<<"\n";
    }
    return 0;
}