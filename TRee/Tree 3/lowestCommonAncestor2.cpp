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
    idx ++;
    if(nodes[idx] == -1){
        return NULL;
    }

    Node* curr = new Node(nodes[idx]);
    curr->left = buildTree(nodes);
    curr->right = buildTree(nodes);

    return curr;

}

Node* LCA(Node* root, int n1, int n2){
    if(root == NULL){ // jab root null ho.. leaf of tree
        return NULL;
    }

    if(root->data == n1 ||root->data == n2){ // jab root hi n1 ya n2 ho... ye subtree ke case me ayega  
        return root;
    }

    Node* left = LCA(root->left, n1, n2);
    Node* right = LCA(root->right, n1, n2);

    
    //if both give a val
    if(left != NULL && right != NULL){
        return root;
    }

    // // if both null
    // if(left == nullptr && right == nullptr){
    //     return NULL;
    // }
    // // if left only null
    // if(left == NULL && right != NULL){
    //     return right;
    // }
    // //if right only null
    // if(left != NULL && right == NULL){
    //     return left;
    // } // all 3 cases in 1 statement using ternary..

    return left == NULL ? right : left;
}

int main(){
    vector<int> nodes = {1,2,4,-1,-1,5,-1,-1,3,-1,6,-1,-1};
    Node* root = buildTree(nodes);

    Node* lca = LCA(root, 4, 5);
    cout << "The LCA of the given nodes is : " << lca->data << endl; // 2

    cout << "The LCA of the given nodes is : " << LCA(root, 4, 6)->data << endl; // 1

    cout << "The LCA of the given nodes is : " << LCA(root, 3, 6)->data << endl; // 3

    cout << "The LCA of the give nodes is : " << LCA(root, 3, 9)->data << endl; // -1 aana chahiye magar ye 3 return karega.. ?? baaki to sab sahi hai.. ise check karna hai...
    return 0;
}