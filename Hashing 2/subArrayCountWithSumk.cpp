#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

int countSubArrWithSumK(vector<int> arr, int k){
    int sum = 0;
    int ans = 0;
    unordered_map<int, int> mp; // to store sum ,count
    mp[0] = 1; // size 1 wale subarray ke liye jinka sum k ke equal ho jata hai..

    for(int i=0; i<arr.size(); i++){
        sum += arr[i];
        if(mp.count(sum-k)){
            ans += mp[sum-k];
        }

        // store the sum to check for the next values.(if not exist store, otherwise increases the freq.)
        mp[sum] ++;
    }
    return ans;
}


int main(){
    vector<int> arr = {1,2,3};
    int k = 3;
    cout << "number of subarray with sum = " << k << ": " << countSubArrWithSumK(arr, k); // 2 ((1,2), 3)
    cout << endl;

    vector<int> arr2 = {10,2,-2,-20,10};
    int k2 = -10;
    cout << "number of subarray with sum = " << k2 << ": " << countSubArrWithSumK(arr2, k2); // 3 (10, 2, -2, -20)
// (2, -2, -20, 10)
// (-20, 10)
    return 0;
}