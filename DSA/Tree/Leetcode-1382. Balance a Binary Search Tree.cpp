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
private:
    void inorderTraversal(TreeNode* root, vector<int>& arr) {
        if (root == NULL) {
            return;
        }
        inorderTraversal(root->left, arr);
        arr.push_back(root->val);
        inorderTraversal(root->right, arr);
    }

    TreeNode* buildBST(int l, int r, vector<int>& arr) {
        if (l > r) {
            return NULL;
        }
        int mid = (l + r) / 2;
        TreeNode* root = new TreeNode(arr[mid]);
        root->left = buildBST(l, mid - 1, arr);
        root->right = buildBST(mid + 1, r, arr);
        return root;
    }

public:
    TreeNode* balanceBST(TreeNode* root) {
        vector<int> inorderArray;
        inorderTraversal(root, inorderArray);
        return buildBST(0, inorderArray.size() - 1, inorderArray);
    }
};
