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

    public:    
            Node* head ;
            Node* tail ;
    
            List(){
                head = NULL;
                tail = NULL;

            }

            void push_front(int val){
                Node *newNode = new Node(val);
                if(head == NULL){
                    head = tail = newNode;
                }
                else{
                    newNode->next = head;
                    head = newNode;
                }
            }

            void push_back(int val){
                Node* newNode = new Node(val);
                if(head == NULL){
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
};

bool checkCycle(Node* head){
                Node* slow = head;
                Node* fast = head;
                while(fast!= NULL && fast->next !=NULL){
                    slow = slow->next;
                    fast = fast->next->next;
                    if(slow == fast){
                        cout << "cyclic link list\n";
                        return true;
                        
                    }
                }
                cout << "linked list is not cyclic\n";
                return false;
            }

void printlinkList(Node* head){// ise ham andar bhi likh sakte the list class me ... ek tarika ye bhi hai 
    Node* temp = head;
    while(temp != NULL){
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << "NULL\n";
}

int main(){
    List ll;

    ll.push_back(5);
    ll.push_front(4);
    ll.push_front(3);
    ll.push_front(2);
    ll.push_front(1);

    ll.printList();
    printlinkList(ll.head);
    cout << "same output twice show that both print function work the same\n";
    
    checkCycle(ll.head);

    ll.tail->next = ll.head;//made the given link list cyclic
    cout << "after making the list cyclic\n";
    checkCycle(ll.head);// call the function


    return 0;
}
 
// sfhjkdshf hsglkjhsddkjfh
// need to change and add the codes remaining.. later.