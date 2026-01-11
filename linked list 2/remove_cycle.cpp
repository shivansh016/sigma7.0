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
           Node* head;
           Node* tail;
           List(){
            head = NULL;
            tail = NULL;
           }

           ~List(){

           }

           void push_front(int val){
            Node* newNode = new Node(val);
            if(head == NULL){
                head = tail = newNode;
            }
            else{
                newNode->next = head;
                head = newNode;
            }
           }

        
};

void removeCycle(Node* head){

       if(head == NULL || head->next == NULL){
        cout << "empty link list or single node link list ";
        return;
       }
            Node* slow = head;
            Node* fast= head;
            bool isCycle = false;

            while(fast != NULL && fast->next != NULL){
                slow = slow->next;
                fast = fast->next->next;
                if(slow==fast){
                    cout << "cycle exists\n";
                    isCycle = true;
                    break;
                }
            }
            if(!isCycle){
                cout << "cycle doesn't exist\n";
                return;
            }

            // work starts here....

            slow = head;
            //case 1: cycle starts at head
            if(slow == fast){
                
                while(fast->next != slow){
                    fast = fast->next;
                }
                fast->next = NULL;// remove cycle

           }
           //case 2: cycle not starts at head i.e. somewhere else 
           else{

                Node* prev = fast;
            
                 while(slow != fast){
                    slow = slow->next;
                    prev = fast;// fast ko update se pahle prev me store kiye.. so prev is before the fast when while loop turns false
                    fast = fast->next;
                 }
                prev->next = NULL; //remove cycle
           }
    }

void printList(Node* head){
    Node* curr= head;
    while(curr != NULL){
        cout << curr->data << "->";
        curr = curr->next;
    }
    cout << "NULL\n";
}

int main(){
    List ll;
    ll.push_front(5);
    ll.push_front(4);
    ll.push_front(3);
    ll.push_front(2);
    ll.push_front(1);

    removeCycle(ll.head); // will return cycle doesn't exist
    printList(ll.head);
   
    ll.tail->next = ll.head->next;       // 5 points back to 2
    // printList(ll.head);//now that ll is become cyclic don't try to print otherwise it will go out of bound i.e. keep printing till infinity
    cout << "made changes in list now ....\n";
    removeCycle(ll.head);
    printList(ll.head);
    

    return 0;
}