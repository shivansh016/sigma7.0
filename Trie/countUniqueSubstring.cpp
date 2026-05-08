//1. create a trie suffixes of the given stirng
//2. use the trie to find the Unique substr count.
//3. count the node of the trie ... it'll give the unique prefixes which is same as counting the unique substring.

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
                if(temp->children.count(key[i])== 0){
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

        int nodeCountHelper(Node* root){
            int ans = 0;

            for(pair<char, Node*> p : root->children){
                ans += nodeCountHelper(p.second);
            }

            return ans + 1;
        }

        int countNode(){
            return nodeCountHelper(root);
        }
};


int countUniqueSubstring(string str){

    Trie trie;
//finding the suffix
    for(int i=0; i<str.size(); i++){
        trie.insert(str.substr(i));
    
    
    }

    return trie.countNode();


}

int main(){
    string str = "ababa";
    cout << "UNIQUE COUNT OF SUBSTR : " << countUniqueSubstring(str) << endl; // 10

    return 0;
}