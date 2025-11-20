#include<iostream>
using namespace std;

void printarr(int arr[],int n){
    for (int i = 0; i<n; i++){
        cout<<arr[i]<<",";
    }
    cout<<endl;
}

void insertionSort(int arr[], int n){
    // t.c. = O(n^2)
    for (int i = 1; i<n; i++){ // for loop i==1 se isliye start huui kyuki we consider 1st element as sorted 
        int curr = arr[i];
        int previdx = i-1;
        while ( previdx >= 0 && arr[previdx]>curr){  // for descending order change the condition to less than
            swap(arr[previdx], arr[previdx+1]);
            previdx--;
        }

        arr[previdx+1]=curr; // current ko sort kiya when prev==-1 or arr[prev] not greater than curr

    }

    printarr(arr,n);
}

int main (){
    int arr[5]={5,4,1,3,2};
    int n = sizeof(arr)/sizeof(int);
    insertionSort(arr,n);
    return 0;
}