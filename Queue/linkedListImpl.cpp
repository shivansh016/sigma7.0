#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

    Node(int data){
        this->data = data;
        this->next = NULL;
    }
};

class Queue{
    Node* head;
    Node* tail;
    public:
            Queue(){
                head = NULL;
                tail = NULL;
            }

            void push(int val){// push at back ka code
                Node* newNode = new Node(val);
                if(head == NULL){
                    head = tail = newNode;
                }
                else{
                    tail->next = newNode;
                    tail = newNode;
                }
                
            }

            void pop(){
                if(empty()){
                    cout << "already empty\n"; 
                    return;
                }
                else{
                    Node*temp = head;
                    head = head->next;
                    if(head == NULL){
                        tail = NULL; //tail reset kiya jab empty ho jaye queue..
                    }
                    temp->next = NULL;
                    delete temp;
                }
                
            }

            int front(){
                if(empty()){
                    cout<< "empty queue\n"; 
                    return -1;
                }
                else{
                    return head->data;
                }
            }

            bool empty(){
                return head == NULL;
            }
            

};

int main(){
    Queue q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);

    while(!q.empty()){
        cout << q.front() << "\n";
        q.pop();
    }

    return 0;
}


// all the operations are implemented in O(1) time complexity.....