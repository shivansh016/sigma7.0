#include<iostream>
#include<deque>
using namespace std;

class Queue{
    deque<int> dq;
    public:
        void push(int data){
            dq.push_back(data);
        }

        void pop(){
            if(empty()){
                cout << "already empty .. nothing can be deleted..\n";
                return;
            }
            dq.pop_front();
        }

        int front(){
            if(empty()){
                cout << "empty queue ... nothing to show..\n";
                return -1;
            }
            return dq.front();
        }

        bool empty(){
            return dq.empty();
        }
};

int main(){
    Queue q;
    q.push(4);
    q.push(3);
    q.push(2);
    q.push(1);

    while(!q.empty()){
        cout << q.front() << " ";// 4 3 2 1 since it is a fifo structure...
        q.pop();
    }
    return 0;
}