/* Structure of a Tree Node
class Node {
public:
    int data;
    Node* left, *right;
    Node(int val) {
        data = val;
        left = right = nullptr;
    }
}; */

class Solution {
  public:
    bool isSumProperty(Node *root) {
        // code here
        if(!root ||(!root->left && !root->right))return true;
        int child=0;
        if(root->left!=nullptr)child+=root->left->data;
        if(root->right!=nullptr)child+=root->right->data;
        if(root->data!=child)return false;
        return isSumProperty(root->left) && isSumProperty(root->right);
    }
};
