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

bool isIdentical(Node* root1, Node*root2){ // yad rakhna ye root1 aur root2 ko ham ek ek node pe le ja kar check karenge..
    //base case
    if(root1 == NULL && root2 == NULL){ //jab dono hi null 
        return true;
    }else if(root1 == NULL || root2 == NULL){ // jab ek hi null
        return false;
    }

    if(root1->data != root2->data){
        return false;
    }

    // jab dono ka data match kar jaye to left aur right subtree me check karo
    return isIdentical(root1->left, root2->left) && isIdentical(root1->right, root2->right); // && used so that we return true only when both left and right subtree matches

}

bool isSubtree(Node* root, Node* subroot){
    //base case
    if(root == NULL && subroot == NULL){ //jab dono hi null 
        return true;
    }else if(root == NULL || subroot == NULL){ // jab ek hi null
        return false;
    }



    if(root->data == subroot->data){
        //check for identical in subtree
        if(isIdentical(root, subroot)){ // matlab jab isIdentical true de to hi true dena hai false ke case me sometimes ho sakta hai ki koi node ek se jyada baar ho aur left wali na match kare subroot se par right wali identical ho ....
            return true;
        }
    }

    bool isLeftsubTree = isSubtree(root->left , subroot);
    if(!isLeftsubTree){
        return isSubtree(root->right , subroot); // jab left se na match ho tabhi right me jao ...
    }
    

    return true; // jab isLeftsubtree true de 
}

int main(){
    vector<int> nodes = {1,2,4,-1,-1,5,-1,-1,3,-1,6,-1,-1};
    Node* root = buildTree(nodes);

    Node* subroot = new Node(2);
    subroot->left = new Node(4);
    subroot->right = new Node(5);

    cout << "is subtree(0-false, 1-true) : " << isSubtree(root, subroot) << endl;

    return 0;

}