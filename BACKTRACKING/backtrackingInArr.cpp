#include<iostream>
#include<vector>
#include<string>
using namespace std;

void printArr(int arr[], int n){
    for (int i=0; i<n; i++){
        cout<< arr[i] << " ";

    }
    cout<< endl;
}

void changeArr(int arr[], int n, int i){
    if(i==n){
        printArr(arr, n); // print array of basecase i.e when all value at each index are updated by +1
        return;
    }

    arr[i]=i+1;
    changeArr(arr, n, i+1);
    arr[i] -= 2;

}

int main(){
    int arr[5]={0};
    int n = sizeof(arr)/sizeof(int);
    changeArr(arr, n, 0);
    printArr(arr, n); // prints array after backtracking // subtracting 2 from each index value
    return 0;
}