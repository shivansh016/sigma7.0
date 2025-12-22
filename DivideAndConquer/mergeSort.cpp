#include<iostream>
#include<vector>
using namespace std;

void merge(int arr[], int si, int ei, int mid){
    vector<int>  vec = {0};
    int i = si; // loop for left half
    int j = mid+1; // loop for right half

    

    while(i<=mid && j<=ei){
        if(arr[i]<=arr[j]){
            vec.push_back(arr[i++]);
       }
       else {
            vec.push_back(arr[j++]);
       }
    }

    while(i<=mid){ //int the above while loop one of condition will get fulfilled and the remaining elements are pushed to vector using the other iterator whose value doesn't reach the end i.e. i to mid or , j to end 
        vec.push_back(arr[i++]);
    }
    while(j<=ei){
        vec.push_back(arr[j++]);
    }

    for(int i=si,x=0; i<=ei; i++){
        arr[i] = vec[x++];
    }


}

void mergeSort(int arr[], int si, int ei){
    if(si>=ei){
        return;
    }
    int mid = si + (ei-si)/2;

    mergeSort(arr, si, mid); // for left half of array
    mergeSort(arr, mid+1, ei); // for right half of array

    merge(arr, si, ei, mid);
    
}

void printArr(int arr[], int n){
    for(int i = 0; i<n; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main(){
    int arr[] = {2,5,3,4,7,6};
    int n = sizeof(arr)/sizeof(int);
    mergeSort(arr,0,n-1);
    printArr(arr, n);
    return 0;
}