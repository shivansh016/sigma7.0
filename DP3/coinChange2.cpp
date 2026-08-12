#include<iostream>
#include<vector>
using namespace std;

int change(vector<int> &coins, int amount){
    int n = coins.size();

        vector<vector<int>> dp(n+1, vector<int> (amount + 1));

        for(int i=0; i<=n; i++){
            dp[i][0] = 1; // jab amount 0 then 1 way
        }

        for(int j=1; j<=amount; j++){
            dp[0][j] = 0; // jab coin zero tab 0 way
        }

        for(int i=1; i<=n; i++){
            for(int j=1; j<=amount; j++){
                int coin= coins[i-1];
                if(coin <= j){
                    int ans1 = dp[i][j-coin];
                    int ans2 = dp[i-1][j];
                    dp[i][j] = ans1 + ans2;
                }else{
                    dp[i][j] = dp[i-1][j];
                }
            }
        }

        return dp[n][amount];
}

int main(){
    vector<int> coins = {1,2,5};
    int amount = 5;

    cout << change(coins, amount) << endl;
    return 0;

}