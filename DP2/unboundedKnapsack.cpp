#include<bits/stdc++.h>
using namespace std;

int unboundedKnapTab(vector<int> & val, vector<int> & wt, int W){
    int n = val.size();

    vector<vector<int>> dp(n+1, vector<int> (W+1, 0));

    for(int i=1; i<=n; i++){
        for(int j=1; j<=W; j++){
            int itemVal = val[i-1];
            int itemWt = wt[i-1];

            if(itemWt<=j){
                 dp[i][j] = max(itemVal + dp[i][j-itemWt] , dp[i-1][j]);
            }else{
                dp[i][j] = dp[i-1][j]; 
            }
        }
    }
    return dp[n][W];
}

int main(){
    vector<int> val = {15, 14, 10, 45, 30};
    vector<int> wt = {2, 5, 1, 3, 4};

    int capacity = 7;

    cout << unboundedKnapTab(val, wt, capacity) << endl; //100

    return 0;
}