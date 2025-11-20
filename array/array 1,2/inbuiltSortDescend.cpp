#include<iostream>
#include<algorithm> //for using of sort function
using namespace std;

void printarr(int arr[], int n){
    for (int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main (){
    int arr[] = {1,4,1,3,2,4,3,7};
    int n = sizeof(arr)/sizeof(int);
    sort(arr, arr+8, greater<int>()); // passed a third parameter greater<int>() for descending sorting!!
    printarr(arr, n);

    
    return 0;
}