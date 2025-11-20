#include<iostream>
using namespace std;

void spiralMatrix(int mat[][4], int n, int m){//it is necessary to pass one of the row or column in passing 2d matrix to a function ,, concept of pointers we'll learn later.....
    int srow = 0, scol = 0;
    int erow = n-1, ecol = m-1;
    
    while(srow<=erow && scol<=ecol){
    //top
    for(int j=scol; j<=ecol; j++){
        cout<<mat[srow][j]<<" ";
    }

    //right
    for(int i=srow+1; i<=erow; i++){
        cout<<mat[i][ecol]<<" ";
    }
    
    //bottom
    for(int j=ecol-1; j>=scol; j--){
        if(srow==erow){ //for middle ,, notice how row equality is used in this loop while col values are changing but opposite in case of //left' loop....
            break;
        }
        cout<<mat[erow][j]<<" ";
    }

    //left
    for(int i=erow-1; i>=srow+1; i--){
        if(scol==ecol){
            break;
        }
        cout<<mat[i][scol]<<" ";
    }

    srow++; 
    scol++;
    erow--;
    ecol--;
    }

    cout<<endl;


}

int main (){
    int arr[4][4]={{1,2,3,4},
                    {5,6,7,8},
                    {9,10,11,12},
                    {13,14,15,16}};
    

    spiralMatrix(arr,4,4);

    int arr2[3][4]={{1,2,3,4},
                    {5,6,7,8},
                    {9,10,11,12}};

    spiralMatrix(arr2,3,4);
    return 0;    
}



 // cout<< "Enter array elements:"<<endl;
    // for(int i = 0; i<n; i++){
    //     for ( int j=0; j<m; j++){
    //         cin>>arr[i][j];
    //     }
    // }



    // //for normal output
    // for (int i=0; i<n; i++){
    //     for (int j=0; j<m; j++){
    //         cout<<arr[i][j]<< " ";

    //     }
    //     cout<<endl;
    // }