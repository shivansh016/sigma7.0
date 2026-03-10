#include<iostream>
#include<vector>

using namespace std;

class Node{
    public: 
         int data;
         Node* left;
         Node* right ;

         Node(int data){
            this->data = data;
            left = right = NULL;
         }
};

void inOrder(Node* root ){
    if(root == NULL){
        return ;
    }

    inOrder(root->left);
    cout << root->data << " ";
    inOrder(root->right);
}

Node* insert(Node*root, int val){
    if(root == NULL){
        root = new Node(val);
        return root;
    }

    if(val < root->data){
        root->left = insert(root->left, val);
    }else{
        root->right = insert(root->right , val);
    }

    return root;
}

Node* buildBST(int arr[], int n){
    Node* root = NULL;
    for(int i=0; i<n; i++){
        root = insert(root, arr[i]);
    }
    return root;
}

Node* inorderSuccessor(Node* root){
    if(root == NULL){
        return NULL;
    }
    while(root->left != NULL){
        root = root->left;
    }

    return root;
}

int main(){
    int arr[] = {1,9, 4, 5 , 10 ,11 ,14 , 8, 7};
    int n = sizeof(arr)/sizeof(int);
    Node* root = buildBST(arr, n);
    inOrder(root);
    cout << endl;

    Node* is = inorderSuccessor(root->right);
    cout <<is->data; // 4
    return 0;
}
