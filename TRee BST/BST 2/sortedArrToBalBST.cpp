#include<iostream>
#include<vector>

using namespace std;

class Node{
    public:
        int data;
        Node* left;
        Node* right;
        
        Node(int data){
            this->data= data;
            left = right = NULL;
        }
};

Node* buildBalancedBST(int arr[], int st, int end){
    if(st>end){ // equality isliye nahi include kiya kyunki... agar single arr element hua to uske liye to st aur end same hoga magar wo to ek valid node banni hai... so equality not included.
        return NULL; 
    }
    int mid = st+(end-st)/2;
    Node * curr = new Node(arr[mid]);
    curr->left = buildBalancedBST(arr, st, mid-1);
    curr->right = buildBalancedBST(arr,mid+1, end);

    return curr;
}

// to verify

void preorder(Node* root){
    if(root == NULL){
        return;
    }

    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);

    
}
int main(){
    int arr[] = {3,4,5,6,7,8,9};
    int n = sizeof(arr)/sizeof(int);
    Node* root = buildBalancedBST(arr, 0, n-1);

    preorder(root);
    return 0;
}