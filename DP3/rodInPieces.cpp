#include<iostream>
#include<vector>
using namespace std;

int rodLen(vector<int> &price, vector<int> &length, int rodLength){
    int n= length.size();

    vector<vector<int>> dp(n+1, vector<int> (rodLength + 1, 0));

    for(int i=1; i<=n; i++){
        for(int j=1; j<=rodLength; j++){
            int piece = length[i-1];
            int prc = price[i-1];
            if(piece<=j){
                int ans1= prc + dp[i][j-piece];
                int ans2 = dp[i-1][j];
                dp[i][j] = max(ans1, ans2);
            }else{
                dp[i][j] = dp[i-1][j];
            }
        }
    }

    return dp[n][rodLength];
}

int main(){
    vector<int> price = {1,5, 8, 9, 10, 17, 17, 20};
    vector<int> length = {1,2,3,4,5,6,7,8};
    int rodLength = 8;
    cout << rodLen(price, length, rodLength) << endl; //22

    return 0;
}