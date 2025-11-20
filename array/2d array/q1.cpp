//print the number of 7 that comes in the 2d array

#include<iostream>
using namespace std;

int countSeven(int mat[][3], int n, int m, int key){
    int flag = 0;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(mat[i][j] == key){
                flag += 1;
            }
        }
    }

    cout<< "number of all 7's present in the given 2d array = " << flag;
    return flag;

}

void printarr(int mat[][3], int n, int m){
    cout << "The matrix elements are : " << endl;
    for (int i=0; i<n; i++){
        for (int j=0; j<m; j++){
            cout << mat[i][j] << " ";
        }
        cout<<endl;
    }
}


int main (){
    // int arr[4][4] = {
    //     {10,20,30,40},
    //     {15,25,35,45},
    //     {27,29,37,48},
    //     {32,33,39,50}};

    //     printarr(arr,4,4);
    //     countSeven(arr, 4,4, 7);

    int arr2[2][3] = { {4,7,8},{8,8,7}};

    printarr(arr2,2,3);
    countSeven(arr2, 2,3, 7);

        

    return 0;
}