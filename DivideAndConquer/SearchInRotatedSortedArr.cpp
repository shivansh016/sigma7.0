// written by shivansh before even teacher wrote the code 


#include<iostream>
using namespace std;

int SearchModiBinary(int arr[], int si, int ei, int tar){
    if(si>ei){
        return -1;

    }

    int mid = si+(ei-si)/2;


    if(arr[mid]==tar){
        return mid;
    }

    if(arr[si]<=arr[mid]){ // when mid element lies on line 1
        if(arr[si]<=tar && tar<arr[mid]){
           
            return SearchModiBinary(arr, si, mid-1, tar);  //searchin left part of line 1 
        }
        else{

            return SearchModiBinary(arr,mid+1, ei, tar); //search in right part of line 1 and line 2 complete
        }

    }
    else{// when mid element lies on line 2
        if(arr[mid]<tar && tar<=arr[ei]){
            return SearchModiBinary(arr, mid+1, ei, tar); // search in the right part of line 2
        }
        else{
            return SearchModiBinary(arr, si, mid-1, tar); // searach in the left part of line 2 and line 1 complete
        }
    }
}


int main (){
    int arr[]= {4,5,6,7,0,1,2};
    int n = sizeof(arr)/sizeof(int);
    int tar = 6;
    int si = 0;
    int ei = n-1;
    cout << SearchModiBinary(arr, si, ei , tar); //4 
    return 0;
}