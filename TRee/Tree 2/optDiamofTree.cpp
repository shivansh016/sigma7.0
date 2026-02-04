#include<iostream>
#include<vector>
#include<utility> //for make_pair
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

pair<int, int> diam(Node* root){ // diam, height ka pair
    if(root == NULL){
        return make_pair(0,0);
    }

    pair<int,int> leftInfo = diam(root->left);
    pair<int, int> rightInfo = diam(root->right);

    int currDiam = leftInfo.second + rightInfo.second+ 1; // leftht + rightht + 1
   

    int diameter= max(currDiam, max(leftInfo.first, rightInfo.first));// currDiam, max(left diam, right diam)
    int height =max(leftInfo.second, rightInfo.second) + 1; // max(leftht, rightht) +1

    return {diameter, height};

}

int main(){
    vector<int> nodes = {1,2,4,-1,-1,5,-1,-1,3,-1,6,-1,-1};
    Node* root = buildTree(nodes);

    cout << "diameter of the tree is: " << diam(root).first << endl;//5
    cout << "height of tree 1 : " << diam(root).second << endl; // 3

    idx = -1; //very imp.

    vector<int> nodes2 = {1,2,4,9,10,-1,-1,-1,-1,5,-1,6,-1,7,-1,-1,3,-1,-1};
    Node* root2 = buildTree(nodes2);

    cout << "diameter of the tree 2 is : " << diam(root2).first << endl; //7
    cout << "heigh of the tree 2 : " << diam(root2).second << endl; //5

    return 0;
}
