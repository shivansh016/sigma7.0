#include<iostream>
#include<vector>
#include<queue>
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

static int idx = -1;
Node* buildTree(vector<int> nodes){
    idx ++;
    if(nodes[idx]== -1){
        return NULL;
    }

    Node* currNode = new Node(nodes[idx]);
    currNode->left = buildTree(nodes);
    currNode->right = buildTree(nodes);

    return currNode;
}

void levelOrder(Node* root){
    if(root == NULL){ // pahle hi check kar lo root empty to nahi .. since ham apni q me kuch bhi NULL jaisa nahi push karne wale....
        return;
    }

    queue<Node*> Q; // queue creation
    Q.push(root); // push root 

    while(!Q.empty()){ // loop

        Node* curr = Q.front(); // front ko curr me store kiya aur pop
        Q.pop();
        
        cout << curr->data << " "; //print curr->data

        if(curr->left != NULL){ // agar curr ka left not NULL to push
            Q.push(curr->left);
        }
        if(curr->right != NULL){ // agar curr ka right not NULL to push
            Q.push(curr->right);
        }

    }
    cout << endl;

}

int main(){

    vector<int> nodes = {1,2,4,-1,-1,5,-1,-1,3,-1,6,-1,-1};
    Node* root = buildTree(nodes);

    levelOrder(root); //1 2 3 4 5 6

    return 0;
}