#include<iostream>
#include<vector>
using namespace std;

void heapify(int i, vector<int> &arr, int n){
    int left = 2*i + 1;
    int right = 2*i + 2;
    int maxIdx = i;

    if(left < n && arr[left] > arr[maxIdx]){
        maxIdx = left;
    }
    if(right < n && arr[right] > arr[maxIdx]){
        maxIdx = right;
    }

    if(maxIdx != i){
        swap(arr[i], arr[maxIdx]);
        heapify(maxIdx, arr, n);
    }
}

void heapSort(vector<int> & arr){
    int n = arr.size();

    //1. build maxHeap
    for(int i = n/2-1; i>=0; i--){
        heapify(i, arr, n);
    }

    // 2. taking els to correct pos
    for(int i=n-1; i>=0; i--){
        swap(arr[0], arr[i]);
        heapify(0, arr, i);
    }

}

void printArr(vector<int> & arr){
    for(int i=0; i<arr.size(); i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}


int main(){
    vector<int> nums = {1,4, 2 , 5, 3};
    heapSort(nums);

    // to verify 
    printArr(nums);

    return 0;
}