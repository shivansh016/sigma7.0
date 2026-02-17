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

int idx = -1;
Node* buildTree(vector<int> nodes){
    idx++;
    if(nodes[idx] == -1){
        return NULL;
    }

    Node* curr = new Node(nodes[idx]);
    curr->left = buildTree(nodes);
    curr->right = buildTree(nodes);
    return curr;
}

void kthHelper(Node* root, int k , int currLevel){
    if(root == NULL){
        return;
    }
    if(k == currLevel){
        cout << root->data << " ";
        return; // as when we get to the kth level no need to check for below nodes..
    }
    kthHelper(root->left, k , currLevel +1); // as har next level me currLevel+1 hota hai..
    kthHelper(root->right, k, currLevel+1);


}

void kthLevel(Node*root, int k){
    kthHelper(root,k ,1); // as root ka level 1 hota hai...
}

int main(){
    vector<int> nodes = {1,2,4,-1,-1,5,-1,-1,3,-1,6,-1,-1};
    Node*root = buildTree(nodes);
    int k;
    cout << " enter the level :" << endl;
    cin>> k;
    kthLevel(root, k);
}
