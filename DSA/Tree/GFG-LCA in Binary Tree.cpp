/*
Definition for Node
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
  public:
    Node* lca(Node* root, int n1, int n2) {
        //  code here
        if(root==nullptr || root->data==n1 || root->data==n2) return root;
        Node* l=lca(root->left,n1,n2);
        Node* r=lca(root->right,n1,n2);
        if(l==nullptr)return r;
        if(r==nullptr) return l;
        return root;
    }
};
