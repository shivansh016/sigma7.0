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

int sumOfNodes(Node* root){
    if(root == NULL ){
        return 0;
    }

    int leftS = sumOfNodes(root->left);
    int rightS = sumOfNodes(root->right);

    return leftS + rightS + root->data;
}

int main(){
    vector<int> nodes = {1,2,4,-1,-1,5,-1,-1,3,-1,6,-1,-1};
    Node* root = buildTree(nodes);

    cout << "sum of nodes in tree : " << sumOfNodes(root); // 21
    cout << endl;

    idx =-1; //very important 
    vector<int> nodes2 = {1,2,4,-1,-1,5,-1,6,-1,7,-1,-1,3,-1,-1};
    Node* root2 = buildTree(nodes2);

    cout << "sum of nodes in tree2 : " << sumOfNodes(root2); // 28
    cout << endl;



    return 0;

}