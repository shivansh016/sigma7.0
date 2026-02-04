#include<iostream>
#include<queue>
#include<vector>
#include<map>
#include<utility>
using namespace std;

class Node{
    public:
        int data;
        Node* left;
        Node* right;
        Node(int data){
            this->data = data;
            left = right = NULL;
        }
};


int idx = -1;
Node* buildTree(vector<int> &nodes){
    idx++;
    if(nodes[idx] == -1){
        return NULL;
    }

    Node* curr = new Node(nodes[idx]);
    curr->left = buildTree(nodes);
    curr->right = buildTree(nodes);

    return curr;
}

void topView(Node* root){
    queue<pair<Node*, int>> q; // Node, hd
    map<int, int> m; // key- hd, val-Node->val

    q.push(make_pair(root,0)); // root ki hd = 0

    while(!q.empty()){
        pair<Node*, int> curr = q.front();
        q.pop();

        Node* currNode = curr.first;
        int currHD = curr.second;

        if(m.count(currHD) == 0){
            m[currHD] = currNode->data;
        }

        if(currNode->left != NULL){
            pair<Node*, int> left = make_pair(currNode->left, currHD-1); // as left me hd 1 se kam hoti hai
            q.push(left);
        }

        if(currNode->right != NULL){
            pair<Node*, int> right = make_pair(currNode->right, currHD+1);
            q.push(right);
        }

    }

    for(auto it: m){
        cout << it.second << " ";
    }
    cout << endl;

}

int main(){
    vector<int> nodes = {1,2,4,-1,-1,5,-1,-1,3,-1,6,-1,-1};
    Node* root = buildTree(nodes);

    topView(root); // 4 2 1 3 6

    return 0;

}

