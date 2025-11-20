#include<iostream>
using namespace std;

void printarr(int arr[], int n ){
    for (int i = 0; i < n; i++){
        cout<<arr[i]<<",";

    }
    cout<<endl;
}

void countSort(int arr[], int n){
    int freq[100000];//initial declared range for freq arr
    int minVal = INT32_MAX, maxVal = INT32_MIN;

    for (int i = 0; i<n; i++){
        minVal = min(minVal,arr[i]);
        maxVal = max(maxVal,arr[i]);

    }
    //O(n)
    //first step, array elements to freq index and their freq in value of the freq array;
    for (int i = 0; i < n; i++){
        freq[arr[i]]++;
    }
    //O(range) = max - min value = range
    //second step, freq index to array elements
    for (int i = minVal, j= 0; i <= maxVal; i++){
        while(freq[i] > 0){
            arr[j++] = i;
            freq[i]--;
        }
    }

    printarr(arr,n);

}

int main (){
    int arr[]={1,4,1,3,2,4,3,7};
    int n = sizeof(arr)/sizeof(int);
    countSort(arr,n);
    return 0;
}