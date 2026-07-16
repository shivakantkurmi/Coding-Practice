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
    unordered_map<long long, int> mp;
    int ans = 0;

    void dfs(TreeNode* root, long long currSum, int target) {
        if (!root) return;

        currSum += root->val;

        // Count paths ending at current node with sum = target
        ans += mp[currSum - target];

        // Add current prefix sum
        mp[currSum]++;

        dfs(root->left, currSum, target);
        dfs(root->right, currSum, target);

        // Backtrack
        mp[currSum]--;
    }
    public:
    int pathSum(TreeNode* root, int targetSum) {
        mp[0] = 1;          // Empty prefix
        dfs(root, 0, targetSum);
        return ans;
    }
};
