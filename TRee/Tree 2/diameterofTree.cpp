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


int height(Node* root){
    if(root == NULL){
        return 0;
    }

    int leftht = height(root->left);
    int rightht = height(root->right);

    return max(leftht, rightht) + 1;
}

int diam(Node* root){ //O(n^2)
    if(root == NULL){
        return 0;
    }

    //case 1 :
    int currDiam = height(root->left) + height(root->right) + 1; // root ko include karte hue jab diam ho ... left diam+ right + 1
    //case 2: jab subtree se diameter ki value aaye
    int leftDiam = diam(root->left); //for left subtree
    int rightDiam = diam(root->right);// for right subtree

    // since max se ham do hi variable compare kar sakte..

    // int maximum = max(leftDiam , rightDiam);
    // maximum = max(maximum, currDiam);
    // return maximum;

    return max(currDiam, max(leftDiam, rightDiam));
}

int main(){
    vector<int> nodes = {1,2,4,-1,-1,5,-1,-1,3,-1,6,-1,-1};
    Node* root = buildTree(nodes);

    cout << "diameter of the tree is: " << diam(root) << endl;

    idx = -1; //very imp.

    vector<int> nodes2 = {1,2,4,9,10,-1,-1,-1,-1,5,-1,6,-1,7,-1,-1,3,-1,-1};
    Node* root2 = buildTree(nodes2);

    cout << "diameter of the tree 2 is : " << diam(root2) << endl;

    return 0;
}