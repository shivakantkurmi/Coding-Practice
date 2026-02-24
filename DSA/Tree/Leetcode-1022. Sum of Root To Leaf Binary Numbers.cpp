/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void solve(TreeNode* root, int val, int &sum){
        if(root == nullptr) return;

        val = (val << 1) | root->val;

        if(root->left == nullptr && root->right == nullptr){
            sum += val;
            return;
        }

        solve(root->left, val, sum);
        solve(root->right, val, sum);
    }

    int sumRootToLeaf(TreeNode* root) {
        int sum = 0;
        solve(root, 0, sum);
        return sum;
    }
};
