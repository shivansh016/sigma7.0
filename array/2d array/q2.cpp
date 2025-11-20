#include<iostream>
using namespace std;

void sumSecRow( int (*mat)[3], int n, int m){
    int sum = 0;
    
        for(int j=0; j<m; j++){
            sum += mat[1][j]; // second row i==1
        }

        cout << "sum of elements of second row = " << sum << endl;
}

int main (){
    int nums[3][3] = {{1,4,9}, {11,4,3}, {2,2,3} };
    sumSecRow(nums, 3, 3);

    return 0;
}