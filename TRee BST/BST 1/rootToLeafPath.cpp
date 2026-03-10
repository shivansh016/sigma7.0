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

// printpath
void printPath(vector<int> &path){
    cout <<"path : ";
    for(int i=0; i<path.size(); i++){
        cout << path[i] << " ";
    }
    cout << endl;
}

//path helper
void pathHelper(Node* root, vector<int> & path){
    if(root == NULL){
        return;
    }

    path.push_back(root->data);
//check if you reached leaf 
    if(root->left == NULL && root->right == NULL){
        printPath(path);
        path.pop_back();// pop_back as you backtrack..
        return;
    }

    pathHelper(root->left, path);
    pathHelper(root->right, path);

    path.pop_back(); // apne level par popback kiya backtrack karte waqt
    return;
}

void rootToLeafPath(Node* root){
    vector<int> path;
    pathHelper(root, path);
    return;
}


int main(){
    vector<int> arr = {8,5,3,1,4,6,10,11,14};
    int n = arr.size();
    Node* root= buildBST(arr, n);
    rootToLeafPath(root);
    return 0;
}