#include<iostream>
#include<string>
#include<stack>
using namespace std;

void pushAtBottom(stack<int> &s, int val){
    if(s.empty()){
        s.push(val);
        return;
    }

    int temp = s.top();
    s.pop();
    pushAtBottom(s, val);
    s.push(temp);
    
}

void reverseStack(stack<int> &s){
    if(s.empty()){
        return;
    }

    int temp = s.top();
    s.pop();
    reverseStack(s);
    pushAtBottom(s, temp);
}

int main(){
    stack<int> a;

    a.push(4);
    a.push(3);
    a.push(2);
    a.push(1);
    while(!a.empty()){
        cout << a.top() << " ";
        a.pop();
    }

cout << endl;

    a.push(4);
    a.push(3);
    a.push(2);
    a.push(1);

    reverseStack(a);

    while(!a.empty()){
        cout << a.top() << " ";
        a.pop();
    }
    
    return 0;
}