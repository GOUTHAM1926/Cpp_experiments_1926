#include <iostream>
// include<vector>
#include <cstdint>
using namespace std;
int main()
{//this approach time complexity is  : O(n^4)
    // // bool A;
    // // bool B;
    // // bool C;
    // // bool D;
    // std::vector<bool> G={true,false};
    // // bool one=((!A) || B);
    // // bool two=(!(A && C));
    // // bool three=(C || D);
    // // bool four=( (!D || !A));
    // for(bool A : G){
    //     for(bool B : G){
    //         for(bool C : G){
    //             for(bool D : G){
    //                 bool one=((!A) || B);
    //                 bool two=(!(A && C));
    //                 bool three=(C || D);
    //                 bool four=( (!D || !A));
    //                 if(one && two && three && four){
    //                 std::cout<<(A)<<" "<<(B)<<" "<<(C)<<" "<<(D)<<std::endl;

    // }}}}}
    //this approach time complexity is : O(n) 
    for (uint8_t i = 0; i <= 15; i++)
    {
        uint8_t x = i & 0x0F;
        uint8_t A = (x & 0x08) >> 3;
        uint8_t B = (x & 0x04) >> 2;
        uint8_t C = (x & 0x02) >> 1;
        uint8_t D = x & 0x01;
        bool one = ((!A) | B);
        bool two = (!(A & C));
        bool three = (C | D);
        bool four = ((!D | !A));
        if(one && two && three && four){
           // std::cout<<(+A)<<" "<<(+B)<<" "<<(+C)<<" "<<(+D)<<std::endl; // +A means uint8_t variable A is converted into int A,before printing,or else uint8_t variable will print ,(or) convert into int.
        std::cout<<int(A)<<" "<<int(B)<<" "<<int(C)<<" "<<int(D)<<std::endl;
        }
    }
}