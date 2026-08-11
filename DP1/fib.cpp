#include<iostream>
#include<vector>

using namespace std;

int recFeb(int n){
    if(n== 0 || n==1){
        //cout << "rec_";
        return n;
    }

    return recFeb(n-1) + recFeb(n-2);
}

int recMem(int n, vector<int> &dp){
    if(n== 0 || n== 1){
        //cout << "dip_";
        return n;
    }

    if(dp[n] != -1){
        return dp[n];
    }

    dp[n] = recMem(n-1, dp) + recMem(n-2, dp);
    return dp[n];
}

int recTab(int n){
    //check this out 
    vector<int> tab(n+1, 0);
    tab[0] = 0;
    tab[1] = 1;

    for(int i=2; i<=n; i++){
        tab[i] = tab[i-1] + tab[i-2];
    }

    return tab[n];
}

int main(){
    int n = 6;

    cout << recFeb(n) << endl; // 0 1 1 2 3 5 8... ans-> 8

    vector<int> dp(n+1, -1);

    cout << recMem(n, dp) << endl;

    cout << recTab(n);

    return 0;

}