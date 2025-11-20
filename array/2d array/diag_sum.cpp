#include<iostream>
using namespace std;

// //O(n^2)
// int diagonalSum(int mat[][4],int n){

//      int sum=0;
//     //for pd
//     for (int i = 0; i<n; i++){
//         for (int j=0; j<n; j++){
//             if(i==j){
//                 sum += mat[i][j];

//             }
//             else if(j==n-i-1){ //as we used else if condition here so it will by default not count the repeating case where both i==j and j=n-i-1 ...... as else if will run only when if condition (i==j) is false
//                 sum += mat[i][j];
//             }
//         }

//     }
    
//     cout<< "sum =" << sum <<endl;
    
//     return sum;
// }

// int diagonalSum2(int mat[][3],int n){ // en example for odd order matrix

//      int sum=0;
    
//     for (int i = 0; i<n; i++){
//         for (int j=0; j<n; j++){
//             if(i==j){
//                 sum += mat[i][j];

//             }
//             else if(j==n-i-1){ //as we used else if condition here so it will by default not count the repeating case where both i==j and j=n-i-1 ...... as else if will run only when if condition (i==j) is false
//                 sum += mat[i][j];
//             }
//         }

//     }
    
//     cout<< "sum for odd order array=" << sum <<endl;
    
//     return sum;
// }


//O(n)
int diagonalSum(int mat[][4], int n){
    int sum = 0;
    for (int i=0; i<n; i++){
        sum += mat[i][i];//pd
        if (i != n-i-1){
            sum += mat[i][n-i-1];//sd
        }
    }

    cout << "sum =" << sum << endl;

}
//O(n)
int diagonalSum2(int mat[][3], int n){
    int sum = 0;
    for (int i=0; i<n; i++){
        sum += mat[i][i];//pd
        if (i != n-i-1){ 
            sum += mat[i][n-i-1];//sd
        }
    }

    cout << "sum for odd order array=" << sum << endl;
    return sum;
}

int main(){
    int arr[4][4]={{1,2,3,4},
                   {5,6,7,8},
                   {9,10,11,12},
                   {13,14,15,16}};
    
    int arrodd[3][3]={{1,2,3},
                      {4,5,6},
                      {7,8,9}};
    
    diagonalSum(arr,4);
    diagonalSum2(arrodd,3);


    return 0;

}