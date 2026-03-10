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

Node* insert(Node* root, int val){ //O(logn)
    if(root == NULL){
        Node* root = new Node(val);
        return root;
    }
// when some nodes do exist ...
    if(val < root->data ){//left subtree
        root->left = insert(root->left, val);
    }else{// right subtree
        root->right = insert(root->right, val);
    }

    return root;
    
}

Node* buildBST(int arr[], int n){
    Node * root = NULL;

    for(int i=0; i<n; i++){// n times logn.. O(nlogn)
         root = insert(root, arr[i]);
    }

    return root;
}

void inOrder(Node* root){
    if(root == NULL){
        return;
    }

    inOrder(root->left);
    cout<< root->data << " ";
    inOrder(root->right);

}

int main(){
    int arr[6] = {5,1,3,4,2,7};
    Node* root = buildBST(arr, 6);
    inOrder(root);
cout << endl;
    int arr2[9] = {8,5,3,1,4,6,10 ,11, 14};
    Node * root2 = buildBST(arr2, 9);
    inOrder(root2); 

    cout << endl;
    return 0;
}