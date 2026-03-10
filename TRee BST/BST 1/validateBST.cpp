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
        Node* root = new Node(val);
        return root;
    }

    // if node exist // search for the right position and insert..
    if(val < root->data){
        root->left = insert(root->left, val);
    }else{
        root->right = insert(root->right, val);
    }

    return root;
}

Node* buildBST(int arr[], int n){
    Node* root = NULL;
    for(int i = 0; i<n; i++){
        root = insert(root, arr[i]);
    }
    return root;
}

void inorder(Node* root){
    if(root == NULL){
        return;
    }

    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

bool helperValidate(Node* root, Node* min, Node* max){
    if(root == NULL){
        return true;
    }

    if(min != NULL && root->data < min->data){ // check for current node range...
        return false;
    }
    if(max != NULL && root->data > max->data){ // ...
        return false;
    }

    bool left = helperValidate(root->left, min, root);
    bool right = helperValidate(root->right, root, max);

    return left && right;// true only when both left and right give true... for each node..
}

bool validateBST(Node* root){
    return helperValidate(root, NULL , NULL);
}

int main(){
    int arr[9] = {8,5,3,1,4,6,10,11,14};
    Node* root = buildBST(arr, 9);
    inorder(root) ;
    cout << validateBST(root) << endl;//1

    root->data = 15;// now made the BST invalid
    inorder(root);
    cout << validateBST(root) << endl; //0

    return 0;
}