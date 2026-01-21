#include<iostream>
#include<deque>
using namespace std;

int main(){
    deque<int> dq;

    dq.push_front(3);
    dq.push_front(2);
    dq.push_front(1);

    dq.push_back(4);
    dq.push_back(5);
    dq.push_back(6);

    while(!dq.empty()){
        cout<< dq.front() << " "; // 1 2 3 4 5 6 
        dq.pop_front();
    }


    return 0;
}
