#include<iostream>
using namespace std;

int searchKeybrute(int mat[][4], int n, int m, int key){
    
    for (int i=0; i<n; i++){
        for (int j=0; j<m; j++){
            if(key == mat[i][j]){
                cout<<"key found at position :"<<i << "," << j << endl;
                
                return 1;
            }
        }
    }
    
        return -1;
    
}

int main (){
    int arr[4][4] = {
        {10,20,30,40},
        {15,25,35,45},
        {27,29,37,48},
        {32,33,39,50}
    };

    searchKeybrute(arr,4,4,33);
    int result = searchKeybrute(arr,4,4,59);//here we are managing the return -1 value with our result variable otherwise it doesn't shows anything when key not found


    if(result == -1){
        cout<< "key not found in matrix." << endl;
    }

    return 0;
}

