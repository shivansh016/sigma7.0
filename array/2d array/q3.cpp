// transpose of a matrix //interchange row to column and vice versa;


// created another array named transpose to store the elements of given array as if we use same array then it repeats the elements ....


#include<iostream>
using namespace std;

void printarr(int mat[][4], int n, int m){
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cout << mat[i][j] << " ";
        }
    cout << endl;
    }
}

void transpose(int mat[][4], int n, int m){
    int transpose[4][4];
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            transpose[j][i] = mat[i][j];
        }
    }

    printarr(transpose, n, m);
}

int main (){
    int arr[4][4] = {
        {10,20,30,40},
        {15,25,35,45},
        {27,29,37,48},
        {32,33,39,50}};
        printarr(arr,4,4);

        cout << endl;
        cout << endl;
        
        transpose(arr,4,4);

        return 0;
    }
