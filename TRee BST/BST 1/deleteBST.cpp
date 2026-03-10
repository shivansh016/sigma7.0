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
    Node * root = NULL;
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

Node* IS(Node* root){
    while(root->left != NULL){ // loop te reach the left most node of the subtree..
        root = root->left;
    }
    return root;
// why we didn't check the condition of nULL here ?? == > its becaue IS if for the third case and already we checked in case1 and case 2 that the root->left and right aren't null in the case 3.
}

Node* deleteNode(Node* root, int target){// return the updated root after deletion of target
    if(root == NULL){
        return NULL;
    }
    if(target < root->data){ // left subtree
        root->left = deleteNode(root->left, target);
    }else if(target > root->data){ // right subtree
        root->right = deleteNode(root->right, target);
    }else {
        // root == val
        // case 1. 0 subchild or leaf node
        if(root ->left == NULL && root->right == NULL){
            delete root;
            return NULL;
        }else if(root->left == NULL || root->right == NULL ){//case 2. 1 subchild(jab left ya right me se ek koi null ho, dono null ka case 1 me pahle hi ho jayega..)
            // if(root->left != NULL){
            //     return root->left;
            // }else{
            //     return root->right;
            // }
            return root->left== NULL ? root->right : root->left;
        }else{// case 3. 2 subchild jab dono hi subchild NULL na ho..
            Node* is = IS(root->right); // right isliye pass kiya kyunki right me hi is hota hai, left most wali node
            root->data = is->data;
            root->right = deleteNode(root->right, is->data);
            return root;

        }
    }
}

int main(){
    vector<int> arr = {8,5,3,1,4,6,10,11,14};
    int n = arr.size(); // sizeof() tells the capacity while arr. size() tells the actual size..
    cout << n << endl;
    Node* root = buildBST(arr, n);
    inOrder(root);
    cout << endl;

    root = deleteNode(root, 4);// leaf node case 1.
    inOrder(root);
    cout << endl;

    root = deleteNode(root, 10);// 1 subchild , case 2.
    inOrder(root);
    cout << endl;

    root = deleteNode(root, 8);// 2 subchild, case 3.
    inOrder(root);
    cout << endl;

    return 0;
}
