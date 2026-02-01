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

static int idx= -1;
Node* buildTree(vector<int> nodes){
    idx++;
    if(nodes[idx] == -1){
        return NULL;
    }

    Node* curr = new Node(nodes[idx]);
    curr->left = buildTree(nodes);
    curr->right = buildTree(nodes);

    return curr;
}

int NodeCount(Node* root){
    if(root == NULL){
        return 0;
    }

    int leftCt = NodeCount(root->left); // leftcount to count nodes in left subtree...
    int rightCt = NodeCount(root->right); // rightcount to count nodes in right subtree...

    int currCt = leftCt + rightCt + 1; // 1 khud ki node ka count.. baaki tum jante hi ho 
    return currCt;

}

int main(){
    vector<int> nodes = {1,2,4,-1,-1,5,-1,-1,3,-1,6,-1,-1};
    Node* root = buildTree(nodes);

    cout << "no. of nodes in tree : " << NodeCount(root); // 6
    cout << endl;

    idx =-1; //very important 
    vector<int> nodes2 = {1,2,4,-1,-1,5,-1,6,-1,7,-1,-1,3,-1,-1};
    Node* root2 = buildTree(nodes2);

    cout << "number of nodes in tree : " << NodeCount(root2); // 7
    cout << endl;



    return 0;

}