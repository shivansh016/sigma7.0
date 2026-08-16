#include<bits/stdc++.h>
using namespace std;

int catalanRec(int n){
    if(n==1 || n==0){
        return 1;
    }
    int ans = 0;
    for(int i=0;i<n; i++){
        ans +=  catalanRec(i)* catalanRec(n-1-i);
    }

    return ans;
}

int catalanMem(int n, vector<int> & dp){
    if(n==0 || n==1){
        return 1;
    }

    if(dp[n] != -1){
        return dp[n];
    }

    int ans = 0;
    for(int i=0; i<n; i++){
        ans += catalanMem(i, dp) * catalanMem(n-i-1, dp);
    }

    dp[n] = ans;
    return dp[n];
}

int catalanTab(int n){
    if(n==0 || n==1){
        return 1;
    }

    vector<int> dp(n+1, 1);

    for(int i=2; i<=n; i++){
        dp[i] = 0;
        for(int j=0; j<i; j++){
            dp[i] += dp[j]*dp[i-1-j];
        }
    }

    return dp[n];
}

int main(){
    //rec
    cout << catalanRec(4) << endl; //14

    //Mem
    int n= 4;
    vector<int> dp(n+1, -1); //storage size should be N+1
    cout << catalanMem(n, dp) << endl; //14

    //tab
    cout << catalanTab(n) << endl; //14
    return 0;
}