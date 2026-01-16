#include<iostream>
#include<string>
#include<stack>
using namespace std;

bool isValid(string str){
    stack<char> s;

    for (int i =0; i<str.size(); i++){
        char ch = str[i];

        if(ch == '(' || ch == '{' || ch == '['){
            s.push(ch);
        }
        else{ // closing bracket
            if(s.empty()){ // jab jyada no. of closing bracket ho
                return false;
            }
            char top = s.top();
            if(top == '[' && ch == ']' ||
               top == '(' && ch == ')' ||
                top == '{' && ch == '}'){
                    s.pop();

                }

            else{
                return false; // jab match na ho
            }
        }
    }

    return s.empty();
}

int main(){
    string st1 = "[{()}]))"; // false;
    string st2 = "[{()}]"; // true;
    string st3 = "({[[[})"; //false

    cout << isValid(st1) << endl; //0
    cout << isValid(st2) << endl; // 1
    cout << isValid(st3) << endl; // 0

    return 0;
}