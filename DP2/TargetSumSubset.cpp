#include<iostream>
#include<vector>
using namespace std;

bool targetSumSubarray(vector<int> &arr, int target, int st ,int end){
    if(st > end){
        return false;
    }
    if(target == 0){
        return true;
    }

    int sum = 0;
    if(sum + arr[st] <= target){
        sum += arr[st];
        st++;
        if(sum == target){
            return true;
        }else{
            return targetSumSubarray(arr, target-sum, st, end);
        }
    }else{
        st++;
        return targetSumSubarray(arr, target, st, end);
    }
}


bool targetSumSubarrTab(vector<int> &arr, int target){
    
    int n = arr.size()-1;
    vector<vector<int>> dp(n+1, vector<int> (target+1, 0));

    for(int i=1; i<=n; i++){
        for(int j=1; j<=target; j++){
            if(arr[i-1] <= j){
                dp[i][j] = max(arr[i-1] + dp[i-1][j - arr[i-1]] , dp[i-1][j]);
            }else{
                dp[i][j] = dp[i-1][j];
            }
        }
    }

    // for(int i=0; i<n; i++){
    //     for(int j=0; j<target; j++){
    //         cout << dp[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    return dp[n][target] == target;
}

int main(){
    vector<int> arr = {4,2,7,1,3};
    int target = 7;
    cout << targetSumSubarray(arr, target, 0, arr.size()-1) << endl;
    cout << targetSumSubarrTab(arr, target) << endl;

    int target2 = 18;
    cout << targetSumSubarray(arr, target2, 0, arr.size()-1) << endl;
    cout << targetSumSubarrTab(arr, target2)<< endl;

    return 0;
}