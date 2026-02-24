#include<iostream>       //to include input/output stream
#include<string>         //to include string library
using namespace std;     //to avoid using std:: before every standard library function
int main(){              // main function - execution starts from here
    string steps[] = {      // declares an array named steps of string type  and holds text
        "Put the fork and knife on the table.",
        "Push the chair back from the table.",
        "Stand up from the chair.",
        "Turn towards the door of the dining room.",
        "Walk around any obstacles (e.g., table, cat).",
        "Walk straight to the dining room door.",
        "Place your hand on the doorknob.",
        "Turn the doorknob clockwise.",
        "Pull the door open.",
        "Step through the doorway into the corridor.",
        "Release the doorknob.",
        "Walk forward in the corridor until you reach the staircase.",
        "Place right foot on the first step.",
        "Lift left foot and place it on the next step.",
        "Repeat until reaching the top of the staircase.",
        "Turn left at the top of the stairs.",
        "Walk forward until you reach the first door on the left.",
        "Place your hand on the doorknob.",
        "Turn the doorknob clockwise.",
        "Push the door open.",
        "Step into the bathroom.",
        "Release the doorknob.",
        "Close the bathroom door."
    };
    int totalSteps =  sizeof(steps)/sizeof(steps[0]);
  /* sizeof(steps) gives the total memory size (in bytes) of the entire steps array
    sizeof(steps[0]) gives the memory size (in bytes) of just the first element of the array
     and by dividing the total size of the array by the size of the single element ,
     we will get theexact no.of elments in the array,which is then stored in the totalSteps variable*/
    
    cout<<sizeof(steps)<<"\n"<<sizeof(steps[0]);

    for (int i=0;i<totalSteps ; i++){
        cout << "Step" << (i+1) <<":" << steps[i] <<"\n" ;
    }
}
