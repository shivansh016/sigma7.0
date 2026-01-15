#include<iostream>
#include<string>
#include<cstdlib>
using namespace std;

template<class T>
class Node{

    public:
        T data;
        Node<T>* next;

        Node<T>(T val){
            data = val;
            next = NULL;
        }
};


template<class tss>
class stack{

    
    Node<tss>* head;

    public:
        stack(){// stack constructor 
            head = NULL;
        }

        void push(tss val){
            //push-front 
            Node<tss> *newNode = new Node<tss>(val);
            if(head == NULL){
                head = newNode;
                return;
            }
            newNode->next = head;
            head = newNode;
        }

        void pop(){
            //pop-front
            if(head == NULL){
                cout << "empty stack\n" ;
                return;
            }
            Node<tss>* temp = head;
            head = head->next;
            temp->next = NULL;
            delete temp;
        }

        tss top(){
            if(head == NULL){
                cout << "empty stack\n";
                exit(1);
            }
            return head->data;
        }

        bool isEmpty(){
            return head == NULL;
        }

};

int main(){
    stack<int> s;

    s.push(4);
    s.push(9);
    s.push(8);
    s.push(123);

    while(!s.isEmpty()){
        cout<< s.top() << "\n";
        s.pop();
    }

    return 0;
}














// list implementation using link list(STL usage)


// #include<iostream>
// using namespace std;
// #include <list>
// #include<string>

// template <class T>
// class stack{
//     list<T> ll;
//     public:

//         void push(T val){
//             ll.push_front(val);

//         }

//         void pop(){
//             ll.pop_front();

//         }

//         T top(){
//             return ll.front();
//         }

//         bool isEmpty(){
//             return ll.size() == 0;
//         }
// };

// int main(){
//     stack<int> s;
//     s.push(4);
//     s.push(1);
//     s.push(2);
//     s.push(9);

//     while(!s.isEmpty()){
//         cout << s.top() << "\n";
//         s.pop();
//     }
//     return 0;

// }