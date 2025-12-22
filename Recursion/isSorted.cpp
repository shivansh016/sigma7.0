#include<iostream>
using namespace std;

bool isSorted(int arr[], int n, int i ){
    //base case
    if(i == n-1){// last element is always sorted so no need to check for n-1 
        return true;
    }

    //recursive case
    if(arr[i] > arr[i+1]){
        return false;
    }
    
       return isSorted(arr, n, i+1);
}

int main (){
    int arr[] = { 1,3,5,6,3};
    int n = sizeof(arr)/sizeof(int);
    cout << "array sorted ? : " << isSorted(arr, n, 0) << " (0 means not sorted and 1 means sorted ) " << endl;
    return 0;

}