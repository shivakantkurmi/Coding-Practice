/* A binary tree Node
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    // Constructor
    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};
*/

class Solution {
  public:
    vector<vector<int>> levelOrder(Node *root) {
        // code here
        vector<vector<int>> bfs;
        queue<Node*>q;
        q.push(root);
        while(!q.empty()){
            vector<int> res;
            int n=q.size();
            for(int i=0;i<n;i++){
                Node *node=q.front();
                q.pop();
                res.push_back(node->data);
                if(node->left !=nullptr) q.push(node->left);
                if(node->right !=nullptr) q.push(node->right);
            }
            bfs.push_back(res);
            
        }
        return bfs;
    }
};
