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

int kthAncestor(Node* root , int node, int k){ // ye fucntion kth ancestor ko nahi return kar raha.. rather it is returning the dist. of kth ancestor from the root node each time... lekin jab kth ancestor ki dist. match kar ja rahi to cout kar raha hai kth ancestor ki val ko.. basically agar match kari to k return karega otherwise -1
    if(root == NULL){
        return -1;
    }

    if(root->data == node){
        return 0; 
    }

    int leftDist = kthAncestor(root->left, node, k);
    int rightDist = kthAncestor(root->right, node, k);

    if(leftDist == -1 && rightDist == -1){ // jab left aur right dono se nahi mila to -1 return kar diya hamne..
        return -1;
    }

    int validVal = leftDist == -1 ?  rightDist : leftDist; // check if left me se -1 then return right otherwise return the left valu. which will not be -1
    
    if(validVal + 1 == k){
        cout << "kth ancestor : " << root->data << endl;
    }

    return validVal +1 ;
}

int main(){
    vector<int> nodes = {1,2,4,-1,-1,5,-1,-1,3,-1,6,-1,-1};
    Node* root = buildTree(nodes);

    cout << kthAncestor(root, 5, 2) << endl; // 1 as kth ancestor,, then 2 ->the value of k
    cout << kthAncestor(root, 7, 5) << endl; //-1

    return 0;
}