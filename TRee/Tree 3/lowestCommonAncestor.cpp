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

int idx =-1;
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

bool rootToNode(Node* root, int n, vector<int> & path){ // pass by ref. is very imp... so that same path return ho
    if(root == NULL){// jab null node aa jaye check karte karte-> return false
        return false;
    }

    path.push_back(root->data);// root ke data ko push karo assuming ki neeche kahin to hoga hi n...

    if(root->data == n){ // pahle check kiye kahi root hi to n nahi..
        return true;
    }

    int isLeft = rootToNode(root->left, n, path);// then left me check kiye
    int isRight = rootToNode(root->right, n, path);// then right me check kiye

    if(isLeft || isRight){ // agar dono (left ya right subtree) me se ek ne bhi true diya to poora function true.. matlab exist karti hai node  
        return true;
    }

    path.pop_back(); // agar na exist kare to pahle vector se element ko pop karo ... then false return 
    return false;
}

int LCA(Node* root, int n1, int n2){
    if(root == NULL){
        return -1;
    }

    vector<int> path1;
    vector<int> path2;

    rootToNode(root, n1, path1);// to get the path 1
    rootToNode(root, n2, path2);// to get the path 2

    int LCA = -1;
    // now iterate over both paths to get the LCA
    for(int i=0, j=0; i<path1.size(), j<path2.size(); i++, j++){
        if(path1[i] != path2[j]){
            return LCA; // assuming ki hamara lca to pahle hi lca me store hai use return kar do
        }
        LCA = path1[i]; // otherwise path1 ya 2 me se koi bhi value lca me paas kar do jab dono hi same hai
    }

    return LCA;

}

int main(){
    vector<int> nodes = {1,2,4,-1,-1,5,-1,-1,3,-1,6,-1,-1};
    Node* root = buildTree(nodes);

    cout << "The lowest common ancestor of the tree for given two nodes is : " << LCA(root, 5, 6) << endl; //1
    cout << "The lowest common ancestor of the tree for given two nodes is : " << LCA(root, 3, 6) <<endl; //3
     cout << "The lowest common ancestor of the tree for given two nodes is : " << LCA(root, 4, 5) <<endl; //2
    return 0;
}
