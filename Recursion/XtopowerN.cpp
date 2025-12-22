#include<iostream>
using namespace std;

int pow(int x, int n){
    if(n==0){
        return 1;
    }
    return x* pow(x, n-1);
}

int powOptimized(int x, int n){
    if(n==0){
        return 1;
    }
    int halfPower = powOptimized(x, n/2);
    int halfPowerSq = halfPower * halfPower;

    if(n%2 != 0){
        halfPowerSq = x * halfPowerSq;
    }
    return halfPowerSq;
}

int main(){
    int x, n;
    cout << "Enter base:";
    cin >> x;
    cout << "Enter exponent:";
    cin >> n;   
    cout << x << " raised to the power " << n << " is " << pow(x, n) << endl;
    cout << x << " raised to the power " << n << " using optimized approach is " << powOptimized(x, n) << endl;
    return 0;
}