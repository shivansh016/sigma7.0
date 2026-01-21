#include<iostream>
#include<stack>
#include<queue>
using namespace std;

void reverseQueue(queue<int> &q){
    stack<int> s;
    while(!q.empty()){
        s.push(q.front());
        q.pop();
    }
    while(!s.empty()){
        q.push(s.top());
        s.pop();
    }
    //as stack lifo follow karta hai to jis order me push karte uska reverse aata hai...
}

int main(){
    queue<int> q;

    for(int i = 1; i<= 10; i++){
        q.push(i);

    }

    reverseQueue(q);

    while(!q.empty()){
        cout << q.front() << " ";
        q.pop();
    }
    return 0;
}