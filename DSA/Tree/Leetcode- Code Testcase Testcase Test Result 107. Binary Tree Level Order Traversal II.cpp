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

    void dfs(TreeNode* root, int level, vector<vector<int>>& levels) {
        if (!root) return;

        if (levels.size() == level)
            levels.push_back({});

        levels[level].push_back(root->val);

        dfs(root->left, level + 1, levels);
        dfs(root->right, level + 1, levels);
    }
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>>levels;
        dfs(root,0,levels);
        reverse(levels.begin(),levels.end());
        return levels;
    }
};
