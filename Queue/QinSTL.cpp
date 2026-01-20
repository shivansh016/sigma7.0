#include<iostream>
using namespace std;
#include<queue>

int main(){
    queue<int> q;
    q.push(1);
    q.push(2);
    q.push(3);

    while(!q.empty()){
        cout << q.front() << "\n"; // 1 2 3
        q.pop();
       
    }
    cout<< q.back();// 3
    
    return 0;

}