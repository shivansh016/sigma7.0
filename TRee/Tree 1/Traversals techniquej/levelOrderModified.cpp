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

    Node* curr = new Node(nodes[idx]);
    curr->left = buildTree(nodes);
    curr->right = buildTree(nodes);

    return curr;
}

void levelOrder(Node *root){
    if(root == NULL){
        return ;
    }

    queue<Node*> q;

    q.push(root);
    q.push(NULL);

    while(!q.empty()){
        Node* curr = q.front();
        q.pop();

        if(curr == NULL){
            cout << "\n";
            if(q.empty()){ // so that infinite loop se bach sako in case of last wala NULL
                break;
            }
            q.push(NULL);
        }else{

            cout << curr->data << " ";

            if(curr->left != NULL){
                q.push(curr->left);
            }
            if(curr->right != NULL){
                q.push(curr->right);
            }
        }

    }
}


int main(){

    vector<int> nodes = {1,2,4,-1,-1,5,-1,-1,3,-1,6,-1,-1};
    Node* root = buildTree(nodes);

    levelOrder(root); 

    return 0;
}

// output:
//1
//2 3
//4 5 6  

// now we are able to print each level nodes in a separate line...