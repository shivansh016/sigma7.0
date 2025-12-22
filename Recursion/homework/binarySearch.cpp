#include<iostream>
using namespace std;

int binarySearch(int arr[], int key ,int beg, int n){
     // base case
     if(beg > n-1){
        return -1;
     }

     // work and recursive call
    int mid= (beg+(n-1))/2; // end=n-1

    if(arr[mid] == key){
        return mid;
    }

    else if(arr[mid]>key){
        return binarySearch(arr,key, beg, n-1);
    }
    else {
        return binarySearch(arr, key, mid+1, n);
    }
  

}

int main(){
    int arr[] = {2,3,4,5,6,7,8,9};
    int n = sizeof(arr)/sizeof(int);
    int k = 33;
    cout << "index of " << k << " is : " <<  binarySearch(arr, k, 0, n);
    return 0;
    
}