#include<iostream>
#include<vector>
using namespace std;

class Node{
    public:
        int data;
        Node*left;
        Node* right;
        Node(int data){
            this->data= data;
            left = right = NULL;
        }
};

void getInorder(Node* root, vector<int> & ans){
    if(root == NULL){
        return;
    }
    getInorder(root->left, ans);
    ans.push_back(root->data);
    getInorder(root->right, ans);

}

Node* helper(vector<int> & arr, int st, int end){
    if(st>end){
        return NULL;
    }
    int mid = st + (end-st)/2;
    Node* curr = new Node(arr[mid]);
    curr->left = helper(arr, st, mid-1);
    curr->right = helper(arr, mid+1, end);

    return curr;
}

Node* bstToBalancedBST(Node* root){
    if(root == NULL){
        return NULL;
    }
    vector<int> ans;
    getInorder(root, ans);
    return helper(ans, 0, ans.size()-1);
}

void preOrder(Node* root){
    if(root == NULL){
        return;
    }

    cout << root->data << " ";
    preOrder(root->left);
    preOrder(root->right);
}

int main(){
    Node* root = new Node(6);
    root->left = new Node(5);
    root->left->left = new Node(4);
    root->left->left->left = new Node(3);

    root->right = new Node(7);
    root->right->right = new Node(8);
    root->right ->right->right = new Node(9); // created the bst that we need to balance.

    root = bstToBalancedBST(root);
    preOrder(root);
}

