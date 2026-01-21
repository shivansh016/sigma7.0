#include<iostream>
#include<queue>
#include<string>

using namespace std;

void firstNonRepeatChar(string str){
    queue<char> Q;
    int freq[26] = {0};
    for(int i =0; i< str.size(); i++){
        int ch = str[i];
        freq[ch - 'a']++;
        Q.push(ch);
        while(!Q.empty() && freq[Q.front() - 'a'] > 1){
            Q.pop();
        }
        if(Q.empty()){
            cout << "-1\n";
        }else{
            cout<< Q.front() << "\n";
        }
    }
}

int main(){
    string str = "aabccxb";
    firstNonRepeatChar(str); // a -1 b b b b x 
    return 0;
}
