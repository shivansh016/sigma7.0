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
    public: 
           Node * head;
           Node * tail;

           List(){
            head = NULL;
            tail = NULL;
           }

           void push_front(int val){
            Node * newNode = new Node(val);
            if(head== NULL){
                head = tail = newNode;
            }
            else{
                newNode->next = head;
                head = newNode;
            }
           }

           void printlList(){
            Node* temp = head;
            while(temp != NULL){
                cout << temp->data << "->";
                temp = temp->next;
            }
            cout << "NULL\n";
           }
//search function recursive
           int searchItr(int key){ // tc=O(n)
            int i=0; 
            if(head==NULL){
                cout << "empty linked list";
            }
            Node* temp = head;
            while(temp!= NULL){
                if(temp->data == key){
                    cout << "found at idx = " << i ;
                    return i;                    
                }
                i++;
                temp= temp->next;
            }
            cout << "not found";
            return -1;
           }
};

// int main(){
//     List ll;

//     ll.searchItr(2);
   
// }

int main(){
    List ll;

    ll.push_front(3);
    ll.push_front(2);
    ll.push_front(1);
    ll.printlList();

    ll.searchItr(3);
    return 0;
}