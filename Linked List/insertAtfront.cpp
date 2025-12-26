#include <iostream>
using namespace std;

class Node{
    public: 

    int data;
    Node * next;

    Node(int val){ //CONSTRUCTOR FOR NODE
        data = val;
        next = NULL;
    }
};

class List {

    public:

    Node * head;
    Node * tail;

    List(){//CONSTRUCTOR FOR List
        head = NULL;
        tail = NULL;
    }

    //notice from here :
    void push_front(int val){
        Node * newNode = new Node(val);//dynamic cretion
        if (head == NULL){
            head = tail = NULL;
        }
        else{
            newNode->next = head;
            head = newNode;
        }
    }
};

int main(){
    List ll;

    ll.push_front(3);
    ll.push_front(2);
    ll.push_front(1);
    return 0;

    // pushes 3,2,1 in the linked list named ll
    // doesn't print anything but inside memory : 1->2->3->NULL

}


