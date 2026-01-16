#include<iostream>
#include<string>
#include<stack>
using namespace std;

bool isDuplicate(string str){
    stack<char> s;

    for(int i=0; i<str.size(); i++){
        char ch = str[i];

        if( ch != ')' ){
            s.push(ch);
        }

        else{// jab closing aa jaye
            
            if(s.top() == '('){
                return true; // Duplicate exists
            }
            
            while(s.top() != '('){
                s.pop();
            }
            s.pop(); // jab opening aa jaye to use bhi to pop karna padega...
            
        }
    }
    return false;
}

int main(){
    string st1 = "((a+b))";//ys
    string st2 = "a+b()"; //yes
    string st3 = "(a+b)+c+d(e)"; // no 

    cout << isDuplicate(st1) << "\n";// 1
    cout << isDuplicate(st2) << "\n";// 1
    cout << isDuplicate(st3) << "\n";// 0

    return 0;
}
