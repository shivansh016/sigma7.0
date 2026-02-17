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

int idx= -1 ;
Node* buildTree(vector<int> nodes){
    idx ++;
    if(nodes[idx] == -1){
        return NULL;
    }

    Node* curr = new Node(nodes[idx]);
    curr->left = buildTree(nodes);
    curr->right = buildTree(nodes);

    return curr;
}

Node* LCA(Node* root, int n1, int n2){
    if(root == NULL){
        return NULL;
    }

    if(root->data == n1 || root->data == n2){
        return root;
    }

    Node* left = LCA(root->left, n1, n2);
    Node* right = LCA(root->right, n1, n2);

    if(left != NULL && right != NULL){
        return root;
    }

    return left == NULL ? right : left;
}

int dist(Node* root, int n){ // ye jo root node hai ye lca wali hai..
    if(root == NULL){
        return -1;
    }
    if(root->data == n){
        return 0;
    }

    int left = dist(root->left, n); 
    if(left != -1){// pahle left me check karte chale jao agar mile to +1 karke return..
        return left+1;
    }

    int right = dist(root->right, n);
    if(right != -1){
        return right + 1; // then check ki agar right me exist karti hai to +1 karke return..
    }

    return -1; // matlab left right kahi na mila .. 
}

int minDist(Node* root, int n1, int n2){

    Node* lca = LCA(root, n1, n2);

    int dist1 = dist(lca, n1);
    int dist2 = dist(lca, n2);

    return dist1 + dist2;
}

int main(){
    vector<int> nodes = {1,2,4,-1,-1,5,-1,-1,3,-1,6,-1,-1};
    Node* root = buildTree(nodes);

    cout << "Min dist : " << minDist(root, 4, 6) << endl; //4
    cout << "Min dist : " << minDist(root, 4, 5) << endl; //2
    cout << "Min dist : " << minDist(root, 4, 9); //-1 as 9 DNE
    return 0;

}