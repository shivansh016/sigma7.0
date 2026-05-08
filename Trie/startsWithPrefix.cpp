#include<bits/stdc++.h>
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

        void insert(string key){
            Node* temp = root;
            for(int i=0; i<key.size(); i++){
                if(temp->children.count(key[i]) == 0){
                    temp->children[key[i]] = new Node();

                }
                temp = temp->children[key[i]];
            }
            temp->endOfWord = true;
        }

        bool search(string key){
            Node* temp = root;
            for(int i=0; i<key.size(); i++){
                if(temp->children.count(key[i])){
                    temp = temp->children[key[i]];
                }else{
                    return false;
                }
               
            }

            return temp->endOfWord;
        }

        bool startsWithPrefix(string key){
            Node* temp = root;
            for(int i=0; i<key.size(); i++){
                if(temp->children.count(key[i])){
                    temp = temp->children[key[i]];
                }else{
                    return false;
                }

            }

            return true; // no need to check the end of word.. since we are searching for the prefix.
        }
};



int main(){
    vector<string> words = {"apple", "app", "man", "woman"};
    Trie trie;

    for(int i=0; i<words.size(); i++){
        trie.insert(words[i]);
    }

    cout << "does prefix app exists (0->no, 1-> yes ) : " << trie.startsWithPrefix("app") << endl; //1
    cout << "does prefix 'man' exist(0->no, 1->yes) : " << trie.startsWithPrefix("man" ) << endl; //1 
    cout << "does prefix 'moon' exist : " << trie.startsWithPrefix( "moon"); //0

    return 0;
}
//Output: 

// does prefix app exists (0->no, 1-> yes ) : 1
// does prefix 'man' exist(0->no, 1->yes) : 1
// does prefix 'moon' exist : 0