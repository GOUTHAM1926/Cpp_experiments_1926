#include<iostream>
#include<string>
int main(){
    std::string description[] = { 
        "Exit your dorm room and close the door behind you.",

"Walk straight down the hallway until you reach the main staircase.",

"Go down three flights of stairs to the ground floor.",

"Exit the building through the main entrance.",

"Turn left and walk along the sidewalk for approximately 150 meters, past the library.",

"Turn right at the first intersection onto the main campus quad.",

"Walk diagonally across the quad towards the large brick building with a green dome.",

"Enter the building through the large double doors.",

"Go up the main staircase to the second floor.",

"Turn right at the top of the stairs and walk down the corridor.",

"Your classroom is the third door on the left, room number 205."
};
int totalDescriptions = sizeof(description)/sizeof(description[0]);
std::cout<<"Memory size(in bytes) of entire elements : "<<sizeof(description)<<"\n"<<"Memory size(in bytes) of one element : "<< sizeof(description[0])<<"\n"<<"No.of elements : "<< totalDescriptions <<"\n"<<"\n";
for (int i=0;i<totalDescriptions;i++){
    std::cout<<"step"<<(i+1)<<":"<<description[i]<<"\n";}
    return 0;
}