#include<iostream>
#include<algorithm> // to use the sort() function...
#include<vector>
#include<cstdlib> // for the abs function which gives the absolute or positive value 
using namespace std;

int minAbsDiff(vector<int> a, vector<int> b){
    int minAbsDiff =0;
    sort(a.begin(), a.end());// sorts in ascending order 
    sort(b.begin(), b.end());// sorts in ascending order

    for(int i = 0; i<a.size(); i++){
        minAbsDiff += abs(a[i] - b[i]);
    }

    return minAbsDiff;
}

int main(){
    vector<int> A = {4,1,8,7};
    vector<int> B = {2,3,6,5};
    
    cout << "Minimum absolute difference : " << minAbsDiff(A, B) << endl;

    vector<int> C = {1,2,3};
    vector<int> D = {2,3,1};
    cout << "minimum absolute difference : " << minAbsDiff(C,D) << endl;
    
    return 0;
}