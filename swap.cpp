#include <iostream>
using namespace std;

void swap (int a, int b){
    int temp ;
    temp = a;
    a = b;
    b = temp;

    cout << a << " and " << b;

}

int main (){
    int a = 10;
    int b = 43;
    swap(a,b);
    return 0;
}