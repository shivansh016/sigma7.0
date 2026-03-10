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

Node* insert(Node* root, int val){
    if(root == NULL){
        root = new Node(val);
        return root;
    }

    if(val< root->data){
        root->left = insert(root->left, val);
    }else{
        root->right = insert(root->right, val);
    }
    return root;
}

Node* buildBST(vector<int> nodes, int n){
    Node* root = NULL;
    for(int i=0; i<n; i++){
        root = insert(root, nodes[i]);
    }
    return root;
}

void inOrder(Node* root){
    if(root == NULL){
        return ;
    }

    inOrder(root->left);
    cout << root->data << " ";
    inOrder(root->right);

}

void printInRange(Node* root, int st, int end){
    if(root == NULL){
        return ;
    }

    
    if(st <= root->data && root->data <= end){
        printInRange(root->left, st, end);
        cout << root->data << " ";
        printInRange(root->right, st, end);

        
        // cout << root->data << " ";
        // printInRange(root->left, st, end);
        // printInRange(root->right, st, end); // 8 5 6 10 11
    }else if(root->data < st){
        printInRange(root->right, st, end);
    }else{ // root> end
        printInRange(root->left, st, end);
    }
   
}

int main(){
    vector<int> nodes = {8,5,3,1,4,6,10,11,14};
    int n = nodes.size();

    Node* root = buildBST(nodes, n);
    inOrder(root);
    cout << endl;
    printInRange(root, 5, 12);
    return 0;
}