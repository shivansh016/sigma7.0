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

class info{
    public:
        bool isBST;
        int min;
        int max;
        int sz;

        info(bool isBST, int min, int max, int sz){
            this->isBST= isBST;
            this->min = min;
            this->max = max;
            this->sz = sz;
        }
};


static int maxSize;

info* largestBST(Node* root){

    // if(root == NULL){
    //     return new info(true, INT32_MAX, INT32_MIN, 0);
    // }

    
//jab leaf node ko hi base case bana lenge tab...
    if(root == NULL){ // jab kisi tree me ek hi node ho... ya ek hi subtree node left ya right only...
        return NULL;
    }
    if(root->left == NULL && root->right == NULL){
        return new info(true, root->data, root->data, 1);
    }

    info* leftInfo = largestBST(root->left);// faith...
    info* rightInfo = largestBST(root->right);//faith..

    int currMin = min(min(root->data, leftInfo->min), rightInfo->min); 
    int currMax = max(max(root->data, leftInfo->max), rightInfo->max);
    int currSz = leftInfo->sz + rightInfo->sz +1;

    
    if(leftInfo->isBST 
        &&  rightInfo->isBST 
        && root->data > leftInfo->max  
        && root->data < rightInfo->min){
            maxSize =max(maxSize, currSz);
            return new info(true, currMin, currMax, currSz);
        }
        
        else{
            return new info(false, currMin, currMax, currSz);
        }  
}


int main(){
    Node* root = new Node(50);
    root->left = new Node(30);
    root->left->left = new Node(5);
    root->left->right = new Node(20);

    root->right = new Node(60);
    root->right->left = new Node(45);
    root->right->right = new Node(70);
    root->right->right->left = new Node(65);
    root->right->right->right = new Node(80);

    largestBST(root);
    cout << "max Size : " << maxSize << endl;
    return 0;
}