#include<bits/stdc++.h>
using namespace std;


    int catalanMem(int n, vector<int>&dp){
        if(n==1 || n==0){
            return 1;
        }

        if(dp[n]!=-1){
            return dp[n];
        }
        int ans = 0;

        for(int i=0; i<n; i++){
            ans += catalanMem(i, dp)*catalanMem(n-1-i , dp);
        }
        dp[n] = ans;
        return dp[n];
    }


    int catalanTab(int n){
        vector<int> dp(n+1, 0);
        dp[0] = 1;
        dp[1] = 1;

        for(int i=2; i<=n; i++){
            for(int j=0; j<i; j++){
                dp[i] += dp[j]*dp[i-1-j];
            }
        }

        return dp[n];
    }
    int numTrees(int n) {
        //direct variation of catalan's algo

        //tab
        return catalanTab(n);

        //Mem
        // vector<int> dp(n+1, -1);
        // return catalanMem(n, dp);

//rec O(2^n) will give tle
        // if(n==0 || n==1){
        //     return 1;
        // }

        // int ans = 0;
        // for(int i=0; i<n; i++){
        //     ans += numTrees(i)*numTrees(n-1-i);
        // }

        // return ans;
    }

    int main(){
        cout << numTrees(3) << endl; //5
        return 0;
    }