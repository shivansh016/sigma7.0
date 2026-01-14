#include<iostream>
#include<vector>
using namespace std;

class Stack{
    vector<int> stack;
public:
    void push(int val){
        stack.push_back(val);
    }

    void pop(){
        if(isEmpty()){
            cout << "Stack is empty";
            return;
        }
        stack.pop_back();
    }

    int tos(){
        if(isEmpty()){
            cout << "Stack is empty";
            return -1;
        }
        int lastIdx = stack.size()-1;
        return stack[lastIdx];
    }

    bool isEmpty(){
        if(stack.size() == 0){
            
            return true;
        }
        else{
            return false;
        }
    }
};

int main(){
    Stack s;
    s.push(4);
    s.push(3);
    s.push(2);
    s.push(1);

    while(!s.isEmpty()){
        cout << s.tos() << endl;
        s.pop();
    }


    return 0;
}