#include<iostream>
#include<vector>
#include<string>

using namespace std;

template<class T>
class Stack{
    vector<T> stack;
    public:
        
        void push( T val){
            stack.push_back(val);
            
        }

        void pop(){
            if(isEmpty()){
                cout << "stack is empty\n" ;
                return;
            }
            stack.pop_back();

        }

        T peek(){
            int lastIdx = stack.size()-1;
            return stack[lastIdx];

        }

        bool isEmpty(){
            return stack.size() == 0;
        }
};

int main(){
    Stack<int> s;
    Stack<string> str;

    s.push(4);
    s.push(3);
    s.push(2);
    s.push(1);

    while(!s.isEmpty()){
        cout << s.peek() << "\n";
        s.pop();
    }
    cout <<endl;

    str.push("abhi ");
    str.push("maroge");
    str.push("nahi");

    while(!str.isEmpty()){
        cout << str.peek() << "\n";
        str.pop();
    }
    cout << endl;

    return 0;
}