#include<iostream>
using namespace std;

class Node{
    public:
          int data;
          Node* next;
          Node(int val){
            data = val;
            next = NULL;
          }

};

class List{
    Node *head;
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
                newNode->next= head;
                head = newNode;
            }
           }

           void insert_back(int val){
            Node* newNode = new Node(val);

            if(head== NULL){
                head = tail = newNode;
            }
            else{
                tail->next = newNode;
                tail = newNode;
            }
           }

           void printList(){
            Node* temp = head;
            while(temp != NULL){
                cout << temp->data << "->";
                temp = temp->next;
            }
            cout << "NULL\n";
           }
//notice from here
          int helper(Node *h, int key){
            if(h == NULL){
                return -1;
            }
            if(h->data == key){
                return 0;
            }
            int idx = helper(h->next, key);
            if(idx == -1){
                return -1;
            }
            return idx+1;
          }

            int SearchRec(int key){
            return helper(head, key);
           }


};

int main(){
    List ll;

    ll.insert_front(3);
    ll.insert_back(4);
    ll.insert_front(2);
    ll.insert_front(1);
    ll.insert_back(5);
    
    ll.printList();

    cout << "index of given element: " << ll.SearchRec(5) << endl;
    return 0;
}