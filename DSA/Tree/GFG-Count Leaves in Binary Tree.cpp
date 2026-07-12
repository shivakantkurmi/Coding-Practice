/* A binary tree node has data, pointer to left child
   and a pointer to right child
struct Node
{
    int data;
    Node* left;
    Node* right;
}; */

// Class Solution
class Solution {
    int solve(Node* root) {
        if (!root) return 0;

        if (!root->left && !root->right)
            return 1;

        return solve(root->left) + solve(root->right);
    }

public:
    int countLeaves(Node* root) {
        return solve(root);
    }
};
