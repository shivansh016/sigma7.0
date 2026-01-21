#include<iostream>
#include<queue>
using namespace std;

class Stack{
    queue<int> q1; // jab bhi stl ko use karte data type dena hota hai.. so given the int
    queue<int> q2;
    public:
        void push(int data){
            while(!q1.empty()){
                q2.push(q1.front());
                q1.pop();
            }
            q1.push(data);
            //ab fir se q2->q1 me
            while(!q2.empty()){
                q1.push(q2.front());
                q2.pop();
            }
        }

        void pop(){
            if(empty()){
                cout<< "already empty\n" ;  
                return;
            }
            q1.pop();
        }

        int top(){
            if(empty()){
                cout << "nothing to show as already empty\n";
                return -1;
            }
            else{
                return q1.front();
            }
        }

        bool empty(){
            return q1.empty();
        }
};

int main(){
    Stack s1;
    s1.push(1);
    s1.push(2);
    s1.push(3);
    s1.push(4);

    while(!s1.empty()){
        cout << s1.top() << endl; // 4321 i.e reverse order me dega output
        s1.pop();
    }

    return 0;
}