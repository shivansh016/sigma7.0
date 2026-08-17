//matrix chain multiplication

#include<bits/stdc++.h>
using namespace std;

int mcmRec(int arr[], int i, int j){
    if(i==j){
        return 0;
    }

    int ans = INT_MAX;

    for(int k=i; k<j; k++){
        int cost1 = mcmRec(arr, i, k);
        int cost2 = mcmRec(arr, k+1, j);
        int currCost = cost1 + cost2 + arr[i-1]*arr[k]*arr[j];
        ans = min(ans, currCost);
    }

    return ans;
}

int mcmMem(int arr[], int i, int j, vector<vector<int>> & dp){
    if(i==j){
        return 0;
    }

    if(dp[i][j] != -1){
        return dp[i][j];
    }

    int ans = INT_MAX;

    for(int k=i; k<j; k++){
        int cost1 = mcmRec(arr, i, k);
        int cost2 = mcmRec(arr, k+1, j);
        int currCost = cost1 + cost2 + arr[i-1]*arr[k]*arr[j];
        ans = min(ans, currCost);
    }

    return dp[i][j] = ans;
}

int mcmTab(vector<int> & arr){
    int n = arr.size();

    vector<vector<int>> dp(n, vector<int> (n));


    //initialization
    for(int i=1; i<n; i++){
        dp[i][i] = 0;
    }

    for(int len = 2; len<n; len++){
        for(int i=1; i<=n-len; i++){
            int j= i+len-1;
            dp[i][j] = INT_MAX;
            for(int k=i; k<j; k++){
                int cost1 = dp[i][k];
                int cost2= dp[k+1][j];
                int currAns = cost1 + cost2 + arr[i-1]* arr[k]* arr[j];
                dp[i][j] = min(dp[i][j], currAns);
            }
        }
    }

    return dp[1][n-1];
}

int main(){
    int arr[] = {1,2,3,4,3};
    int n = sizeof(arr)/sizeof(int);

    //RecCode
    cout << mcmRec(arr, 1, n-1) << endl; //30
    //since n-1 matrices from n size ARR, therefore j=n-1 , i=1;

    //memoization
    vector<vector<int>> dp(n, vector<int> (n,-1));
    cout << mcmMem(arr, 1, n-1, dp) << endl; //30

    //tabulation
    vector<int> nums = {1,2,3,4,3};
    cout << mcmTab(nums) << endl; //30
    return 0;

}