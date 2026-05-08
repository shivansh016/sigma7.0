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

        void helper(Node* root, string &ans, string temp){
            for(pair<char, Node*>  child: root->children){
                if(child.second->endOfWord == true){
                    temp += child.first;

                    if(temp.size() > ans.size()){
                        ans = temp;
                    }else if(temp.size() == ans.size()){
                        ans = temp < ans ? temp : ans;
                    }

                    helper(child.second, ans, temp);
                    temp.pop_back();
                }

                
            }
        }

        string longestWordWithPrefixes(){
            string ans = "";
            string temp = "";
            helper(root, ans, temp);

            return ans;

        }


};

string longestWordWithAllPrefixes(vector<string> & words){
    Trie trie;
    for(int i=0; i<words.size(); i++){
        trie.insert(words[i]);
    }

    return trie.longestWordWithPrefixes();
}

int main(){
    vector<string> words = {"a", "ap", "appl", "banana", "app", "apply", "apple"};
    cout << "longest Word With All Prefixes : " << longestWordWithAllPrefixes(words); //apple

    return 0;
}