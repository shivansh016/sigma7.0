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

int transform(Node*root){
    if(root == NULL){
        return 0;
    }

    int oldleft = transform(root->left);
    int oldright = transform(root->right);
    int currOld = root->data;
    
    root->data = oldleft + oldright;

    if(root->left != NULL){ // so that null ho next jaise 4 ka 5 ka ya 6 ka,,, i.e. leaf node ke liye ... ya jisme left ya right me se koi null ho to..
        root->data += root->left->data;
    }
    
    if(root->right != NULL){
        root->data += root->right->data;
    }

    return currOld;
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

    transform(root);
    levelOrder(root); // to verify
//20
//9 6
//0 0 0
    return 0;
}