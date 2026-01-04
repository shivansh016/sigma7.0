#include<iostream>
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
    Node* head;
    Node* tail;

    public:
           List(){
            head = NULL;
            tail = NULL;
           }

           void insert_front(int val){
            Node* newNode = new Node(val);
            if(head == NULL){
                head = tail = newNode;
            }
            else{
                newNode->next = head;
                head = newNode;
            }
           }

           void printList(){
            Node * temp = head;
            while(temp != NULL){
                cout << temp->data << "->";
                temp = temp->next;
            }
            cout << "NULL\n";
           }

           void pop_front(){
            if(head == NULL){
                cout << "link list is already empty\n" ;
            }
            Node* temp = head;// temp isliye banaya so that baad me ise ham delete kar sake
            head = head->next;
            temp->next = NULL;// connection cut kiye
            delete temp;//deleted
           }
};


int main(){
    List ll;
    ll.insert_front(5);
    ll.insert_front(4);
    ll.insert_front(3);
    ll.insert_front(2);
    ll.insert_front(1);

    ll.printList();

    ll.pop_front();
    ll.printList();

    return 0;
}