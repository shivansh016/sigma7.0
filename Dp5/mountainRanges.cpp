#include<bits/stdc++.h>
using namespace std;

int mountainRanges(int n){
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

int main(){
    cout << mountainRanges(4) << endl; // 14

    return 0;
}