#include<iostream>
#include<vector>

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

static int idx = -1;

Node* buildTree(vector<int> nodes){
    idx ++;
    if(nodes[idx] == -1){
        return NULL;
    }

    Node* currNode = new Node(nodes[idx]); // create the Node 
    currNode->left = buildTree(nodes); // left subtree
    currNode->right = buildTree(nodes); // right subtree

    return currNode; 
}

int main(){
    vector<int> nodes = {1,2,4,-1,-1,5,-1,-1,3,-1,6,-1,-1};
    Node* root = buildTree(nodes);// since buildTree root of the tree return karta hai .. so node ka naam root de diya
    cout << "root = " << root->data << endl; // to verify // 1 ayega

    return 0;
}