#include<bits/stdc++.h>
using namespace std;

//rec code will give tle
    int lcsRec(vector<int> & sorted, vector<int> & nums, int n, int m){
        if(n== 0 || m== 0){
            return 0;
        }
        

        if(sorted[n-1] == nums[m-1]){
            
            return 1 + lcsRec(sorted, nums, n-1, m-1);
        }else{
            int ans1= lcsRec(sorted, nums, n, m-1);

            int ans2 = lcsRec(sorted, nums, n-1, m);
            return max(ans1, ans2);
        }
    }

//memoization
    // O(n*m) or n**2 as n== m
    // O(n*m)
    int lcsMem(vector<int>& sorted, vector<int>& nums, int n, int m, vector<vector<int>> &dp){
        if(n==0 || m== 0){
            return 0;
        }

        if(dp[n][m] != -1){
            return dp[n][m];
        }

        if(sorted[n-1] == nums[m-1]){
            dp[n][m] = 1 + lcsMem(sorted, nums, n-1, m-1, dp);
        }else{
            dp[n][m] = max(lcsMem(sorted, nums, n-1, m, dp), lcsMem(sorted, nums, n, m-1, dp));
        }

        return dp[n][m];
    }

    //tabulation 

 int lcsTab(vector<int> & sorted, vector<int> & nums){
        int n= sorted.size();
        int m= nums.size();

        vector<vector<int>> dp(n+1, vector<int>(m+1, 0));

        for(int i=1; i<=n; i++){
            for(int j=1; j<=m; j++){
                if(sorted[i-1] == nums[j-1]){
                    dp[i][j] = 1 + dp[i-1][j-1];
                }else{
                    dp[i][j] = max(dp[i-1][j] , dp[i][j-1]);
                }
            }
        }

        return dp[n][m];
    }

int main(){
    vector<int> nums = {50, 3, 10, 7, 40 ,80};
//appraoch : create a copy arr , sort it, then find the lcs between the copy and original.

    // set<int> st;

        // for(int i=0;i<nums.size(); i++){
        //     st.insert(nums[i]);
        // }
    set<int> st(nums.begin(), nums.end());


        // vector<int> sorted;
        // for(auto it : st){
        //     sorted.push_back(it);
        // }
    vector<int> sorted(st.begin(), st.end());

        int n= sorted.size();
        int m = nums.size();

        //recursion
        cout << lcsRec(sorted, nums, n, m)<< endl;

         //mem
        vector<vector<int>> dp(n+1, vector<int>(m+1, -1));
        cout << lcsMem(sorted, nums, n, m , dp) << endl;

        //tab
         //tabulation
        cout <<  lcsTab(sorted, nums) << endl;

        return 0;

}


