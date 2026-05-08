#include<iostream>
#include<string>
#include<vector>
#include<unordered_map>
using namespace std;

class Node{
    public:
        unordered_map<char, Node*> children;
        bool endOfWord;

        Node(){
            endOfWord = false;
        }
};

class Trie{
    Node* root;
    public: 
        Trie(){
            root = new Node();
        }

        void insert(string key){ //O(L)
            Node* temp = root;
            for(int i=0; i<key.size(); i++){
                if(temp->children.count(key[i]) == 0){
                    temp->children[key[i]] = new Node(); // insert
                }
                temp = temp->children[key[i]];
            }

            temp->endOfWord = true; // marking the endOfWord as 'true' after the for loop.
            
        }

        bool search(string key){ //O(L)
            Node* temp = root;
            for(int i=0; i<key.size(); i++){
                if(temp->children.count(key[i]) == 0){
                    return false;
                }else{
                    temp= temp->children[key[i]];
                }
            }

            return temp->endOfWord; // agar true matlab endOfWord .. else our word is not present.
            
        }
};

int main(){
    vector<string> words = {"the", "a", "there", "their", "thee", "any"};
    Trie trie; //created a Trie named trie;

    for(int i=0; i<words.size(); i++ ){ //O(words.size() * words[i].size())
        trie.insert(words[i]); //O(words[i].size())
    }

    cout << "the exis (0->no, 1-> yes) : " << trie.search("the") << endl ; //1
    cout<< "ant exist (0->no, 1->yes) : " << trie.search("ant") << endl; // 0

    return 0;

}