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
// class Solution {
//     void solve(vector<vector<int>>&paths,vector<int> path, int target,int curr,TreeNode* root){
//         if(!root)return ;
//         path.push_back(root->val);
//         curr+=root->val;
//         if(!root->left && !root->right){
//             if(target==curr)paths.push_back(path);
//             return ;
//         }
//         solve(paths,path,target,curr,root->left);
//         solve(paths,path,target,curr,root->right);
//     }
// public:
//     vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
//         vector<vector<int>>paths;
//         vector<int> path;
//         int curr=0;
//         solve(paths,path,targetSum,curr,root);
//         return paths;
//     }
// };

//optimizing above using refernce instead of path vector sending by value to reduce overhead of memory
class Solution {
    void solve(vector<vector<int>>& paths, vector<int>& path,
               int target, int curr, TreeNode* root) {

        if (!root) return;

        path.push_back(root->val);
        curr += root->val;

        if (!root->left && !root->right) {
            if (curr == target)
                paths.push_back(path);
        } else {
            solve(paths, path, target, curr, root->left);
            solve(paths, path, target, curr, root->right);
        }

        path.pop_back();   // Backtrack
    }

public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> paths;
        vector<int> path;
        solve(paths, path, targetSum, 0, root);
        return paths;
    }
};
