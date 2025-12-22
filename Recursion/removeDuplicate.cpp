#include<iostream>
#include<string>
using namespace std;

void removeDuplicates(string str, string ans, int i , bool seen[]){
    if (i==str.size()){
        cout<<"ans : "<< ans << endl;
        return ;
    }

    char ch = str[i];
    int seenIdx = int(ch-'a');

    if(seen[seenIdx]==1){//already seen -> skip
        removeDuplicates(str, ans, i+1, seen);
    }
    else { //not seen -> make seen value true , then add str[i]to ans and make recursive call
        seen[seenIdx]=true;
        removeDuplicates(str, ans+str[i], i+1, seen);
    }
}

int main(){
    string str = "apnacollege";
    string ans = "";
    bool seen[26] = {false};
    removeDuplicates(str, ans, 0, seen);
    
    return 0;
}