#include <iostream>
using namespace std;

class Node{
    public:
        int data;
        Node * next;

        Node(int val){
            data = val;
            next = NULL;
        }
};

class List{

    public: 

    Node* head;
    Node * tail;

    List(){
        head = NULL;
        tail = NULL;
    }
//notice from here
    void push_back(int val){
        Node * newNode = new Node(val); //dynamic creation of the newNode
        if(head == NULL){
            head = tail = newNode;
        }
        else{
            tail->next = newNode;
            tail = newNode;
        }

    }
};

int main(){
    List ll;
//created a push_back function to insert elements at the end
    return 0;

}