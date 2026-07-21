/* A binary tree Node

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
 */
class Solution {
    void solve(Node* root, int level, vector<vector<int>> &levelOrder){
        if(!root)return ;
        if(levelOrder.size()==level){
            levelOrder.push_back({});
        }
        levelOrder[level].push_back(root->data);
        solve(root->left,level+1,levelOrder);
        solve(root->right,level+1,levelOrder);
    }
  public:
    vector<vector<int>> levelOrder(Node* root) {
        // code here
        vector<vector<int>>levelOrder;
        solve(root,0,levelOrder);
       
        return levelOrder;
    }
};
