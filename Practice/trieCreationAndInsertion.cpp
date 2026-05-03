#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    unordered_map<char, Node*> mp;
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
            if(temp->mp.count(key[i]) == 0){
                temp->mp[key[i]] = new Node();

            }
            temp = temp->mp[key[i]];
        }
        temp->endOfWord = true;
    }

    bool search(string key){
        Node* temp = root;
        for(int i=0; i<key.size(); i++){
            if(temp->mp.count(key[i])){
                temp = temp->mp[key[i]];
            }else{
                return false;
            }
        }
        return temp->endOfWord == true;
    }
};

int main(){
    vector<string> words = {"the", "a", "there", "their", "any", "thee"};
    Trie trie;
    for(int i=0; i<words.size(); i++){
        trie.insert(words[i]);
    }

    cout << "their exist (0->no, 1->yes) : " << trie.search("their"); //1
    cout << "\ntheirs exist : " << trie.search("theirs"); //0

    return 0;
}