#include<stack>
#include<iostream>
using namespace std;

void PushAtBottom(stack<int> &s, int val){
    if(s.empty()){
        s.push(val);
        return;
    }

    int temp = s.top();
    s.pop();
    PushAtBottom(s, val);
    s.push(temp);

}

int main(){
    stack<int> a;

    a.push(3);
    a.push(2);
    a.push(1);

    PushAtBottom(a, 4);

    while(!a.empty()){
        cout << a.top() << "\n";
        a.pop();
    }

    return 0;
}