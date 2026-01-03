//insert at any position and the delete LIST using the destructor (of node and the list class)

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

           ~Node(){
            cout << "destructor of the node for data = " << data << "\n";
            if(next != NULL){
                delete next;
                next = NULL;
            }
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

          ~List(){
            cout << "Destructor of the List " << endl;
            if(head != NULL){
                delete head;
                head = NULL;
            }
          }

          void push_front(int val){
//step 1 : creatin the new node
            Node* newNode = new Node(val);
//step 2 : check if the node list given to us was empty or not if empty directly insert the newNode otherwise ...
            if(head == NULL){
                head = tail = newNode;
            }
//step 2 : otherwise firstly newNode ka next head pe, then head ko newNode pe
            else{
                newNode->next= head;
                head = newNode;
            }
          }

          void push_back(int val){
//step 1 : creation of the new node
            Node* newNode = new Node(val);
//step 2 : if given list was empty
            if(head== NULL){
                head = tail = newNode;
            }
//step 2 (b): when elements exists in the given node
            else{
                tail->next = newNode;
                tail = newNode;
            }
          }

          void printList(){
            Node * temp = head;//create a temporary node initialised by head
            while(temp != NULL){// keep printing the elements at the temp and update temp until the temp does not become NULL
                cout << temp->data << "->";
                temp = temp->next;
            }
            cout << "NULL\n";// at the end print NULL
            
          }

          void insert(int val, int pos){
            Node * newNode= new Node(val);
            Node * temp = head;
            for(int i=1; i<pos-1; i++){
                if(temp == NULL){
                    cout << "enter a valid index";
                }
                temp = temp->next;
            }
            newNode->next = temp->next;
            temp->next = newNode;
          }
};


int main(){
    List ll;

    ll.push_back(6);
    ll.push_back(7);
    ll.push_front(3);
    ll.push_front(2);
    ll.push_front(1);

    ll.insert(4,4);
    ll.insert(5,5);

    ll.printList();

    return 0;
}