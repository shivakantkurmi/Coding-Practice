/*
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};
*/

class Solution {
    bool solve(Node* root, int low, int high){
        if(root==nullptr) return true;
        if((root->data )>=high || (root->data)<=low)return false;
        return solve(root->left,low,root->data) && solve(root->right,root->data,high);
    }
  public:
    bool isBST(Node* root) {
        // code here
        return solve(root,INT_MIN,INT_MAX);
        
    }
};
