#include<iostream>
using namespace std;

//code for finding leftmax array
//code for right max array finding
void trap(int *heights, int n) {
    int leftMax[20000], rightMax[20000]; //as in question given that leftmax of size 2*10^4
    leftMax[0]=INT32_MIN;
    rightMax[n-1]=INT32_MIN;
    
    // cout the first value stored in the leftMax
    cout<<leftMax[0];
    cout<<endl;
//cout other values of leftMax
    for (int i=1; i<n; i++){
        leftMax[i]=max(leftMax[i-1], heights[i-1]);
        cout<< leftMax[i] << ",";
    }

    cout<<endl;
// cout initial values of rightMax
    for (int i=n-2; i>=0; i--){
        rightMax[i]=max(rightMax[i+1], heights[i+1]);
        cout<< rightMax[i] << ",";
    }
    //cout the last VAlue stored in the rightMax
    cout<<rightMax[n-1];
    cout<<endl;

    

}





int main(){
    int heights[7]={4,2,0,6,3,2,5};
    int n = sizeof(heights)/sizeof(int);

    trap(heights, n);
    return 0;

}

//in this code 
// the problem is that when we try to find out the min-heights[i] whenever the system performs intmin-4(-infinity-4=(+infinity)) it makes it intmax due to bit addition so we initialize in a different way refer to code traprainwaternew.cpp