#include<iostream>
#include<string>
using namespace std;

void printSubsets(string str, string subset){
    if(str.size()==0){
        cout << subset << endl;
        return;
    }
    char ch = str[0];
    printSubsets(str.substr(1,str.size()-1), subset + ch); // yes choice i.e. charater included
    printSubsets(str.substr(1,str.size()-1), subset); // no choice i.e character not inluded
}

int main(){
    string str = "abc";
    string subset = "";
    printSubsets(str, subset);
    return 0;
}