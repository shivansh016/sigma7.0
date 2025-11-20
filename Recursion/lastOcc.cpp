#include<iostream>
#include<vector>
#include<string>
using namespace std;

int lastOcc(vector<int> arr, int target, int i){
    if(i==arr.size()){
        return -1;
    }
    int idxFound = 0;

     idxFound = lastOcc(arr, target, i+1);
    if(idxFound == -1 && arr[i] == target){
        if(arr[i] == target){
            return i;
        }
        return idxFound;
       
    }
}

int main(){
    vector<int> arr= {1,2,3,3,4};
    cout << lastOcc(arr, 3, 0) << endl;
    return 0;   
}