// this code was written by me without any help 

#include<iostream>
#include<string>
using namespace std;

void findAllOcc(int arr[], int i,int n, int key){
    if(i==n){
        cout<< "\nsearching done " << endl;
        return;
    }
    if(arr[i]==key){
        cout<< i << " ";
        
    }
    return findAllOcc(arr, i+1, n, key);
}

int main(){
    int arr[]={2,3,4,5,2,2,3};
    int n = sizeof(arr)/sizeof(int);
    int key = 2;
    findAllOcc(arr, 0, n, key);
   return 0;
}
