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
    
    Node * head;
    Node * tail;
public:
    List(){
        head = NULL;
        tail = NULL;
    }
};

int main (){
    List ll;

    // this is just creation of node class which has data and next ptr.
    // then created a List class that will be used to join all the elements(nodes) of the Node class to make it a linked list
    // then creation of the linked list named ll
}