#include <iostream>
using namespace std;

int main () {
    int arr[3][4];
    int n = 3, m = 4;
    cout<< "Enter 2d array's elements:" << endl;

    //for input 

    for (int i=0; i<n; i++){
        for (int j=0; j<m; j++){
            cin>> arr[i][j]; // 0,0 then 0,1 then 0,2 and so on.....
        }
    }

    // for output 

    for (int i=0; i<n; i++){
        for (int j=0; j<m; j++){
            cout << arr[i][j] << " ";
        }
        cout<<endl;
    }

    return 0;

}