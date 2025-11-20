#include<iostream>
using namespace std;

void func(int mat[][4], int n, int m){
    cout << "0th row ptr " << mat << endl;
    cout << "1st row ptr " << mat+1 << endl;
    cout << "2nd row ptr " << mat+2 << endl;

    cout << endl;

}

void func2(int (*mat)[4], int n, int m){
    cout << "0th row ptr " << mat << endl;
    cout << "1st row ptr " << mat+1 << endl;
    cout << "2nd row ptr " << mat+2 << endl;

}

int main (){
    int arr[4][4] = {
        {10,20,30,40},
        {15,25,35,45},
        {27,29,37,48},
        {32,33,39,50}};

    func(arr, 4,4);
    func2(arr, 4,4);
    return 0;
}