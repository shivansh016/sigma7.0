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
    Node* head;
    Node* tail;

    public: 
          List(){
            head = NULL;
            tail = NULL;

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

          void printList(){
            Node* temp = head;
            while(temp != NULL){
                cout << temp->data << "->";
                temp = temp->next;
            }
            cout << "NULL\n";
          }

          int getSize(){
            int sz = 0;
            Node* temp= head;
            while(temp != NULL){
                temp = temp-> next;
                sz++;
            }
            return sz; //NOTE : it will return size counting from 1 to n i.e. number of elements
          }

          void removeNth(int n){
            int size = getSize();
            Node* prev = head;
            for(int i=1; i<size-n; i++){// less than as the prev starts from head which is the first element from starting
              prev = prev->next;
            }
            Node * toDel = prev->next;
            cout << "going to delete : "<< toDel->data << endl;
            prev->next = prev->next->next;
          }
};

int main(){
  List ll;
  ll.push_front(5);
  ll.push_front(4);
  ll.push_front(3);
  ll.push_front(2);
  ll.push_front(1);
  cout << "size is :" <<ll.getSize() << endl ;

  ll.printList();
  ll.removeNth(2);
  ll.printList();
cout << "size is :" <<ll.getSize() ;
  return 0;
}