#include<bits/stdc++.h>
using namespace std;

    bool isMatch(string s, string p) {
        int n= s.size();
        int m= p.size();

        vector<vector<bool>>dp(n+1, vector<bool>(m+1));

        //initialization
        dp[0][0] = true;

        for(int j=1; j<=m; j++){
            if(p[j-1] != '*'){
                dp[0][j] = false;
            }else{
                dp[0][j] = dp[0][j-1];
            }
        }

        for(int i=1; i<=n; i++){
            dp[i][0] = false;
        }

        //bottom up solution

        for(int i=1; i<=n; i++){
            for(int j=1; j<=m; j++){
                if(p[j-1] == '?'){//when it's a question mark we match it with current character and ask for the answer of the left characters in the s and p.
                    dp[i][j] = dp[i-1][j-1];
                }else if(p[j-1] >= 'a' &&  p[j-1] <= 'z'){// when it's a alphabet we match it, if it does -> ask for the left characters and if doesn't, simply store false
                    if(p[j-1] == s[i-1]){
                        dp[i][j] = dp[i-1][j-1];
                    }else{
                        dp[i][j] = false;
                    }
                }else{// when it's a  *, we match it eg: aab, a*=> match and remove the last char of s.. but what if it's like -> abc, abc* = then we simply match the * with empty spcae ... and thus store true if any of the 2 cases becomes true.
                    dp[i][j] = dp[i-1][j] || dp[i][j-1];
                }
            }
        }

        return dp[n][m];
    }


int main(){
    string s = "aa";
    string p = "*a***?***";
    cout << isMatch(s, p) << endl; //1

    return 0;
}