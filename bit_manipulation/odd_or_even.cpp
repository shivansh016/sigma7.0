#include<iostream>
using namespace std;

void oddOrEven(int num){
    if(!(num&1)){
        cout << "even number" << endl;
    }
    else{
        cout << "odd number" << endl;
    }
}

int main(){
    oddOrEven(6);
    oddOrEven(9);
    return 0;
}