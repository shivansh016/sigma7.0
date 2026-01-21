#include<iostream>
#include<queue> 
using namespace std;

queue<int> interleaveQueue(queue<int> &q){
    queue<int> first;
    int n = q.size();
    for(int i=0; i<n/2; i++){
        first.push(q.front());
        q.pop();
    }

    while(!first.empty()){
        q.push(first.front());
        first.pop();
        q.push(q.front());
        q.pop();
    }
    //  //  2-line fix for odd size
    // if(n % 2 != 0){
    //     q.push(q.front());
    //     q.pop();
    // }

    return q;
}
int main(){
    queue<int> q;

    for(int i = 1; i<=10; i++){
        q.push(i);
    }

    interleaveQueue(q);

    while(!q.empty()){
        cout << q.front() << " ";
        q.pop();
    }

    return 0;
}