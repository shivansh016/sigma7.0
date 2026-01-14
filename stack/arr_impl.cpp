#include<iostream>
#include<vector>
using namespace std;
#define Max 10

class stack{
    int list[Max];
    int top = -1;


    public:
        void push(int val){
            if(top == Max){
                cout << "stack overflow\n" ;
                return ;
            }
            top++;
            list[top] = val;
            
            
        }

        void pop(){
            if(top == -1){
                cout << "stack underflow";
                return ;
            }
            
            top --;
            
        }

        void peek(){
            if(top == -1){
                cout << "stack underflow\n";
                return;
            }
            cout << list[top --] << "\n";
        }

        bool isEmpty(){
            if(top == -1){
                cout << "stack is empty\n";
                return true;
            }
            return false;
        }

        bool isFull(){
            if(top == Max){
                cout << "stack is full \n";
                return true;
            }
            return false;
        }




};

int main(){
    stack s;
    s.pop();

    cout << endl;

    s.push(4);
    s.push(3);
    s.push(2);
    s.push(1);

    s.peek();
    s.peek();
    s.peek();
    s.peek();

    s.isEmpty();
    s.peek();

    return 0;
}


