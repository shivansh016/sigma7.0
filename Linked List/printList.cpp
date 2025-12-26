#include<iostream>
using namespace std;

class Node {
    public:
            int data;
            Node* next;

            Node(int val){
                data = val;
                next = NULL;

            }

};

class List {
    public:
            Node* head;
            Node* tail;

            List(){
                head = NULL;
                tail = NULL;
            }

            void printList(){
                Node * temp = head;
                while(temp != NULL){
                    cout << temp-> data << "->";
                    temp = temp->next;
                }
                cout << "NULL";
            }
};

int main (){
    List ll;
    ll.printList();
    return 0;
     
    // shows NULL on the output screen as there is nothing in the linked list so statement after the while loop executed showing NULL
}