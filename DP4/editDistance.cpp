#include<bits/stdc++.h>
using namespace std;

 int minDistance(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();

        vector<vector<int>> dp(n+1, vector<int> (m+1));

        for(int i=0; i<=n; i++){
            dp[i][0] = i;
        }

        for(int j=0; j<=m; j++){
            dp[0][j] = j;
        }

        for(int i=1; i<=n; i++){
            for(int j=1; j<=m; j++){
                if(word1[i-1] == word2[j-1]){
                    dp[i][j] = 0 + dp[i-1][j-1]; // no operation
                }else{
                    dp[i][j] = 1 + min(dp[i][j-1], min( dp[i-1][j],  dp[i-1][j-1])); 
                }
            }
        }

        return dp[n][m];

        // dp[i][j-1], //insertion
         //   dp[i-1][j], // deletion 
        // dp[i-1][j-1]); // replace
    }

int main(){
    string word1 = "horse";
    string word2 = "ros";

    cout << minDistance(word1, word2) << endl;
    return 0;
}
