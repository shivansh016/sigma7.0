#include<bits/stdc++.h>
using namespace std;

int minPartitioning(vector<int> &nums){
    int n= nums.size();

    int totSum =  0;
    for(int i=0; i<n; i++){
        totSum += nums[i];
    }

    int w = totSum/2; 


    vector<vector<int>> dp(n+1, vector<int>(w+1, 0) );

    for(int i=1; i<=n; i++){
        for(int j=1; j<=w; j++){
            if(nums[i-1] <= j){
                int ans1 = nums[i-1] + dp[i-1][j-nums[i-1]] ; // do i-1 so that it doesn't become unbounded knapsack..
                int  ans2 = dp[i-1][j];
                dp[i][j] = max(ans1, ans2);
            }else{
                dp[i][j] = dp[i-1][j];
            }
        }
    }

    int gp1 = dp[n][w];
    int gp2 = totSum - dp[n][w];

    return abs(gp1 - gp2);
}

int main(){
    vector<int> nums  = {1,5 ,11, 6};

    cout << minPartitioning(nums) << endl;

    return 0;
}