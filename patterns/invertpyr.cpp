#include<iostream>
using namespace std;
int main(){
    int n=5;
    //outer loop
    for(int i=n;i>=1;i--) {
        //spaces
        for(int j=n-i;j>=1;j--){
            cout<<" ";
        }
        //stars
        for(int j=2*i-1;j>=1;j--){
            cout<<"*";
        }
        cout<<endl;

    }
    return 0;
}
