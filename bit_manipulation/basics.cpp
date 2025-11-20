#include<iostream>
using namespace std;

int main(){
    cout << (7<<3) << endl; // read as 7 left shift by 3 ; and ans will be 7*[2^3] i.e. 56
    cout << (7>>3) << endl; // read as 7 right shift by 3; and answer will be 7/(2^3) i.e. 0
    cout << (~0) << endl; // read as one's complement of 0 ; output -1

    return 0;
}