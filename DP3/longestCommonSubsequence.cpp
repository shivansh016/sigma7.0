#include<bits/stdc++.h>
using namespace std;

int lcsRec(string &str1, string & str2, int n, int m){
    if(n==0 || m==0){
        return 0;
    }

    if(str1[n-1] == str2[m-1]){
        return 1 + lcsRec(str1, str2, n-1, m-1);
    }else{
        int ans1 = lcsRec(str1, str2, n, m-1);
        int ans2 = lcsRec(str1, str2, n-1, m);
        return max(ans1, ans2);
    }
}


string lcsRecAns(string &str1, string &str2, int n, int m ){
    if(n== 0 || m== 0){
        return "";
    }

    if(str1[n-1] == str2[m-1]){
        
        //when i was using a answer string ..
        //currentAns = str1[n-1] + currentAns; //prepending makes it in forward order.
        //currentAns += str[n-1]; //would have cause it to be in reverse order.
        return lcsRecAns(str1, str2, n-1, m-1) + str1[n-1]  ;// here we are appending as we go in bottom up approach.
    }else{
        string ans1 = lcsRecAns(str1, str2, n, m-1);
        string ans2 = lcsRecAns(str1, str2, n-1, m);

        return ans1.size()>= ans2.size() ? ans1 : ans2;
    }


}

int lcsMem(string & s1, string & s2, int n, int m, vector<vector<int>> &dp){
    if(m== 0 || n==0){
        return 0;
    }

    if(dp[n][m] != -1){
        return  dp[n][m];
    }

    if(s1[n-1] == s2[m-1]){
        dp[n][m] = 1 + lcsMem(s1, s2, n-1, m-1, dp);
    }else{
        dp[n][m] = max(lcsMem(s1, s2, n-1, m, dp), lcsMem(s1, s2, n, m-1, dp));
    }
    return dp[n][m];

}

int lcsTab(string &s1, string&s2){
    int n= s1.size();
    int m= s2.size();

    vector<vector<int>> dp(n+1, vector<int> (m+1, 0));
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            if(s1[i-1] == s2[j-1]){
                dp[i][j] = 1 + dp[i-1][j-1];
            }else{
                dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
            }
        }
    }
    return dp[n][m];
}


int main(){
    string str1 = "abcdge";
    string str2 = "abedg";
    int n= str1.size();
    int m = str2.size();

    string ans  = "";
    cout << lcsRec(str1, str2, n, m) << endl ; // 4
    cout << lcsRecAns(str1, str2, n, m) << endl; 

    vector<vector<int>> dp(n+1 ,vector<int>(m+1, -1 )) ;

    cout << lcsMem(str1, str2, n, m, dp) << endl;

    cout << lcsTab(str1, str2) << endl;

}