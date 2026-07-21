/* The Node structure is
struct Node
{
    int data;
    Node* left;
    Node* right;
}; */
class Solution {
public:
    int minDepth(Node *root) {
        if (!root)
            return 0;

        // Leaf node
        if (!root->left && !root->right)
            return 1;

        // Only right subtree exists
        if (!root->left)
            return 1 + minDepth(root->right);

        // Only left subtree exists
        if (!root->right)
            return 1 + minDepth(root->left);

        // Both subtrees exist
        return 1 + min(minDepth(root->left), minDepth(root->right));
    }
};
