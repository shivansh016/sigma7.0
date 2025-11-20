#include<iostream>
using namespace std;

int clearinrange(int num, int i, int j){
    int a = (~0) << (j+1);
    int b = (1<<i)-1;
    int mask = a|b;
    num = num & mask;
    return num;
}



int main (){
    cout << clearinrange(15,1,3) << endl;//0001=1
    cout << clearinrange(31,2,4) << endl;//00011=3
    return 0;
}