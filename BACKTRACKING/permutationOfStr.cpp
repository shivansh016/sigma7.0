#include<iostream>
#include<string>
using namespace std;

void permutations(string str, string ans){
    int n = str.size();
    if(n==0){ // bc ... when str becomes empty ... print the ans
        cout<< ans << endl;
        return;
    }
    for(int i=0; i<n; i++){
        char ch = str[i];
        string nextst = str.substr(0,i) + str.substr(i+1,n-i-1);
        permutations(nextst, ans + ch);
        
    }
}

int main(){
    string str = "abc";
    string ans = "";
    permutations(str, ans);
    return 0;
}