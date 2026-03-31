#include<iostream>
#include<vector>
using namespace std;

class Node{
    public:
        string key;
        int val;
        Node* next;

        Node(string key, int val){
            this->key = key;
            this->val = val;
            next = NULL;
        }

        ~Node(){
            if(next != NULL){
                delete next;
            }
        }
};

class hashTable{
    
        int totSize;
        int currSize;
        Node** table;
        int hashfunction(string key){
            int idx = 0;
            for(int i=0; i<key.size(); i++){
                idx = idx + (key[i] * key[i]) % totSize;
            }
            return idx%totSize;
        }

        void rehash(){
            int oldSize = totSize;
            Node** oldTable = table;

            totSize = 2*oldSize;
            currSize = 0;
            table = new Node*[totSize];
            for(int i=0; i<totSize;i++){
                table[i] = NULL;
            }

            // storing old values..
            for(int i=0; i<oldSize; i++){
                Node* temp = oldTable[i];
                while(temp!= NULL){
                    insert(temp->key, temp->val);
                    temp = temp->next;
                }
                // deleting the nodes
                if(oldTable[i] != NULL){
                    delete oldTable[i]; // lekin isse sirf head delete hoga... baki elements ke liye destructor use karenge jo ki upar likh rakha hai..
                }
            }
            delete[] oldTable; // since ab isme sirf NULL values rah jayengi har index par to poori table hi ek sath delete kar denge.
        }

    public:
        hashTable(int Size ){
           totSize = Size;
           currSize = 0;

           table = new Node*[totSize]; //but now it will have some garbage value... but we want to initialize it by NULL so using loop we will do that work

           for(int i=0; i<totSize; i++){
            table[i] = NULL;
           } 
        }

        // now we need to implement 3 important functions of the hastable... insert(), erase(), search()..

        void insert(string key, int val){// insert the key-val pair
            int idx = hashfunction(key);

            Node* newNode = new Node(key, val); // creating newNode 
        
            newNode->next = table[idx]; // insertion at beg.
            table[idx ]= newNode;

            currSize++;

            double lambda = currSize/(double)totSize;
            if(lambda> 1){
                rehash();
            }
        }

        bool exists(string key){
            int idx = hashfunction(key);

            Node* temp = table[idx];
            while(temp!= NULL){
                if(temp->key == key){ //found
                    return true;
                }
                temp = temp->next;
            }
            return false;
        }

        int search(string key){ // takes inp. key and return the value of the key..
            if(!exists(key)){
                return -1;
            }else{
                int idx = hashfunction(key);
                Node* temp = table[idx];

                while(temp != NULL){
                    if(temp->key == key){
                        return temp->val;
                    }
                    temp = temp->next;
                }
            }
        }

        void erase(string key){ // takes inp. key and remove the key-val pair of that key
            int idx = hashfunction(key);

            Node* temp = table[idx];
            Node* prev = temp;

            while(temp!= NULL){
                if(temp->key == key){ // erase
                    if(prev == temp){// when to remove is head node
                        table[idx] = temp->next;
                    }else{// any node in between
                        prev->next = temp->next;
                    }
                    break;
                }
                prev = temp;
                temp = temp->next;
            }
        }

        void print(){

            for(int i=0; i<totSize; i++){

                cout << "idx" << i << "->";

                Node* temp = table[i];

                while(temp != NULL){
                    cout << "(" << temp->key << "," << temp->val << ")->";
                    temp = temp->next;
                }
                cout << endl;
            }
        }

       

}; 


int main(){
    hashTable ht(5); // we are creating an instance of the hashtable named ht with size 5..

    ht.insert("India", 150);
    ht.insert("China", 150);
    ht.insert("US", 33);
    ht.insert("Russia", 15);
    ht.insert("Nepal", 10);

    ht.print();

    cout << "____________\n" << endl;

    ht.erase("US");

    ht.print();

    ht.erase("China");

    cout << "------------\n" << endl;
    ht.print();
    
    return 0;
}
