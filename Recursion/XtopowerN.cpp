#include<iostream>
using namespace std;

int pow(int x, int n){
    if(n==0){
        return 1;
    }
    return x* pow(x, n-1);
}

int main(){
    int x, n;
    cout << "Enter base:";
    cin >> x;
    cout << "Enter exponent:";
    cin >> n;   
    cout << x << " raised to the power " << n << " is " << pow(x, n) << endl;
    return 0;
}