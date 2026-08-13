#include<bits/stdc++.h>
using namespace std;

int longestCommonSubstringTab(string &s1, string &s2){
    int n = s1.size();
    int m = s2.size();

    int ans = 0;

    //NOte here dp[i][j] means that the len of lcs ending at idx = i, and idx = j

    vector<vector<int>> dp(n+1, vector<int> (m+1, 0));

    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            if(s1[i-1] == s2[j-1]){
                dp[i][j] = 1 + dp[i-1][j-1];
            }else{
                dp[i][j] = 0;
            }
            ans = max(dp[i][j], ans);
        }
    }
    return ans;
}



//mem code is for hw.. 

int  main(){
    string s1 = "abgce";
    string s2 = "abcde";

    cout << longestCommonSubstringTab(s1, s2) << endl; //2

    return 0;
}