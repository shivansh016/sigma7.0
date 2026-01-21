#include<iostream>
#include<deque>
using namespace std;

class Stack{
    deque<int> dq;
    public:
        void push(int data){
            dq.push_back(data);
        }

        void pop(){
            if(empty()){
                cout << "empty stack... nothing to delete\n";
                return ;
            }
            dq.pop_back();
        }

        int top(){
            if(empty()){
                cout << "empty stack... nothing to show..\n";
                return -1;
            }
            return dq.back();
        }

        bool empty(){
            return dq.empty();
        }


};

int main(){
    Stack s;
    for(int i = 1 ; i<=5; i++){
        s.push(i); // push karenge 1 2 3 4 5
    }

    while(!s.empty()){
        cout << s.top() << " "; // 5 4 3 2 1 as stack is a lifo str.
        s.pop();
    }

    return 0;

}