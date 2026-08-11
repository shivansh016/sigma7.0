#include<iostream>
#include<vector>
using namespace std;


//Brute REc(O(2^n))
int knapSack(vector<int> val, vector<int>wt, int W, int n){
    if(n== 0 || W == 0){
        return 0;
    }

    int itemWt = wt[n-1];
    int itemVal = val[n-1];

    if(itemWt <= W){
        int ans1 = knapSack(val, wt, W-itemWt, n-1) + itemVal; //included
        int ans2 = knapSack(val, wt, W, n-1); //not included

        return max(ans1, ans2);
    }else{
        return knapSack(val, wt, W, n-1); //when obj wt is invalid.. i.e. more than the capacity
    }
}

//knapsack memoization

int knapMem(vector<int> val, vector<int> wt, int w , int n, vector<vector<int>> &dp){
    if(n==0 || w==0){
        return 0;
    }

    if(dp[n][w] != -1){
        return dp[n][w];
    }

    int itemWt = wt[n-1];
    int itemVal = val[n-1];

    if(itemWt <= w){
        int ans1 = knapMem(val, wt, w-itemWt, n-1,  dp) + itemVal;
        int ans2 = knapMem(val, wt, w, n-1, dp);
        dp[n][w] = max(ans1, ans2);
    }else{
        dp[n][w] = knapMem(val, wt, w, n-1,  dp);
    }

    return dp[n][w];
}

int knapTab(vector<int>val, vector<int> wt, int w, int n ){
    vector<vector<int >> dp(n+1, vector<int> (w+1 , 0));

    for(int i=1; i<n+1; i++){
        for(int j=1; j<w+1; j++){
            int itemVal = val[n-1];
            int itemWt = wt[n-1];
            if(itemWt <= w){
                dp[i][j] = max(knapTab(val, wt, w-itemWt, n-1) + itemVal, knapTab(val, wt, w, n-1));
            }else{
                dp[i][j] = knapTab(val, wt, w, n-1);
            }
        }

        return dp[n][w];
    }
}

int main(){
    vector<int> wt = {2,5,1,3,4};
    vector<int> val = {15,14,10,45,30};
    int n = 5;
    int w = 7;

    cout << knapSack(val, wt, 7, 5) << "\n"; //75

    //for memoization part
    vector<vector<int>> dp(n+1, vector<int>(w+1, -1));
    cout << knapMem(val, wt, w, n,  dp) << endl;

    //for the tabulation
    cout << knapTab(val, wt, w, n) << endl;

    return 0;
}