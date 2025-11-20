#include<iostream>
using namespace std;

int main(){
    int rows;
    cout << "enter rows : ";
    cin >> rows;
    int cols;
    cout << "enter cols : ";
    cin >> cols;

//declaration

    int ** matrix = new int *[rows];
    for (int i=0; i<rows; i++){
        matrix[i] = new int[cols];
    }

//to store data and printing 
    int x = 1;
    for (int i=0; i<rows; i++){
        for (int j=0; j<cols; j++){
            matrix[i][j] = x++;
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    
// to show that matrix[i][j] and *(*(matrix + i)+j) are same 
    cout << matrix[2][2] <<endl;
    cout << *(*(matrix + 2) + 2);

    return 0;
}