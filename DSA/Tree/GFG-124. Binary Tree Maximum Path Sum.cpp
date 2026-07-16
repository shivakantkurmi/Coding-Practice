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
    int solve(TreeNode* root, int& ans, int curr){
        if(!root)return 0;
        int left=max(0,solve(root->left,ans,curr+root->val));
        int right=max(0,solve(root->right,ans,curr+root->val));
        ans=max(ans,left+right+root->val);
        return root->val+ max(left,right);
    }
public:
    int maxPathSum(TreeNode* root) {
        int ans=INT_MIN;
        solve(root,ans,0);
        return ans;
    }
};
