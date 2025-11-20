#include<iostream>
using namespace std;

void func(int mat[][4], int n, int m){
    cout << "0th row ptr " << mat << endl;
    cout << "1st row ptr " << mat+1 << endl;
    cout << "2nd row ptr " << mat+2 << endl;

    cout << endl;

    cout << "0th row value " << *mat << endl; //address of the 0th row 
    cout << "1st row value " << *(mat+1) << endl; //address of the 1st element of 1st row
    cout << "2nd row value " << *(mat+2) << endl; //address of the 2nd element of 2nd row
    
}

void funcValue(int mat[][4], int n, int m){

    cout << "1st row, 3rd col element :" << *(*(mat+1)+3);
}



int main (){
    int arr[4][4] = {
        {10,20,30,40},
        {15,25,35,45},
        {27,29,37,48},
        {32,33,39,50}};

    func(arr, 4,4);

    funcValue(arr, 4,4);
   
    return 0;
}