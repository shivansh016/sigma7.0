#include<iostream>
#include<vector>
using namespace std;

int stair(int n){
    if(n==0 || n== 1){
        return 1;
    }
    return stair(n-1) + stair(n-2);
}

int stairMem(int n, vector<int>&dp){
    if(n== 0 || n==1){
        return 1;
    }
    if(dp[n] !=-1){
        return dp[n];
    }

    dp[n] = stairMem(n-1, dp) + stairMem(n-2, dp);
    return dp[n];
}

int stairTab(int n){
    vector<int> dp(n+1, 1);
    for(int i=2; i<=n; i++){
        dp[i] = dp[i-1] + dp[i-2];
    }

    return dp[n];

}

int main(){
    int n= 4;

    cout << stair(n) << endl;

    vector<int> dp(n+1, -1);
    cout << stairMem(n, dp) << endl;
    cout << stairTab(n) << endl;
}

// 5
// 5
// 5