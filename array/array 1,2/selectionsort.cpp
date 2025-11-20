#include<iostream>
using namespace std;

void printArr(int *arr, int n){
    for (int i = 0; i<n; i++){
        cout<< arr[i] << ",";
    }
    cout<<endl;
}

void selectionSort( int *arr, int n){
    for (int i = 0; i<n-1; i++){
        int minidx = i;
        for (int j = i+1; j<n; j++){
            if (arr[j]<arr[minidx]) {
                minidx = j;
            }
            }
        swap (arr[i],arr[minidx]);
        }
    printArr(arr,n);
    }



int main (){
    int arr[6] = {3,2,5,1,6,7};
    int n = sizeof(arr)/sizeof(int);
    selectionSort(arr,n);
}

