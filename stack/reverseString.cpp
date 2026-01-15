#include<iostream>
#include<string>
#include<stack>

using namespace std;

string reverseString(string str){
    string ans ;
    stack<char> s;
    for(int i = 0; i< str.size() ; i++){
        s.push(str[i]);
    }

    while(!s.empty()){
        char temp = s.top();
        ans += temp;
        s.pop();
    }
    return ans;
}

int main(){
    string st= "abcd";

    cout << "reversed = " << reverseString(st) << "\n";
    return 0;
}