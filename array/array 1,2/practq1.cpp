#include<iostream>
using namespace std;

void printarr( char arr[], int n){
    for ( int i =0; i<n; i++){
        cout<< arr[i]<< ",";
    } 
    cout<<endl;
}


void sortchar(char arr[], int n){
    // t.c. = O(n^2)
    for (int i = 1; i<n; i++){ // for loop i==1 se isliye start huui kyuki we consider 1st element as sorted 
        int curr = arr[i];
        int previdx = i-1;
        while ( previdx >= 0 && arr[previdx]<curr){  // for descending order change the condition to less than
            swap(arr[previdx], arr[previdx+1]);
            previdx--;
        }

        arr[previdx+1]=curr; // current ko sort kiya when prev==-1 or arr[prev] not greater than curr

    }

    printarr(arr,n);
}


int main (){
    char arr[]={'e','a','b','f','d','c'};
    int n = sizeof(arr)/sizeof(char);
    sortchar(arr,n);
    return 0;
}