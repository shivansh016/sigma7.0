#include<iostream>
#include<stack>
using namespace std;

// push costly...


// class Queue{
//     stack<int> s1;
//     stack<int> s2;
//     public: 

//         void push(int data){
            
//             // s1 --> s2
           
//                 while(!s1.empty()){
//                     s2.push(s1.top());
//                     s1.pop();
//                 }

//                 // push now in s1
//                 s1.push(data);

//                 //s2-->s1
//                 while(!s2.empty()){
//                     s1.push(s2.top());
//                     s2.pop();
//                 }
            
            
//         }

//         void pop(){
//             if(s1.empty()){
//                 cout << "already empty\n";
//                 return ;
//             }
//             else{
//                 s1.pop();
//             }
            
//         }

//         int front(){
//             if(s1.empty()){
//                 cout << "empty queue\n";
//                 return -1;
//             }
//             else{
                
//                 return s1.top();
//             }
//         }

//         bool empty(){
//             if(s1.empty()){
//                 return true;
//             }
//             else{
//                 return false;
//             }
//         }

// };

//pop costly...//remember isme worst case me front bhi O(n) me jata jai... jab pahle front ko call karte hai (pop se pahle)..
class Queue{
    stack<int> s1;
    stack<int> s2;
    public:
        void pop(){
            if(empty()){
                cout<< "empty queue\n";
                return;
            }
            if(s2.empty()){
                    while(!s1.empty()){
                        s2.push(s1.top());
                        s1.pop();
                    }
                
            }   
            s2.pop(); // O(n)                         
            
            
        }

        void push(int data){
            s1.push(data);
        }

        int front(){
            if(empty()){
                cout<< "empty queue \n" ;
                return -1;
            }
            else{
                if(s2.empty()){
                while(!s1.empty()){
                    s2.push(s1.top());
                    s1.pop();
                }
            }
            return s2.top(); //O(1)
        }

        }

        bool empty(){
            return s1.empty() && s2.empty(); // agar s1,s2 empty to hi hamara queue empty .. ..
        }
};

int main(){
    Queue q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);

    while(!q.empty()){
        cout<< q.front() << endl;
        q.pop();

    }
    return 0;
}
