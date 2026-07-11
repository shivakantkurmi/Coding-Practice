/*
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};
*/

class Solution {
  public:
    vector<int> leftView(Node *root) {
        // code here
        queue<Node*> q;
        vector<int> leftView;
        if(!root)return leftView;
        q.push(root);
        while(!q.empty()){
            int sz=q.size();
            for(int i=0;i<sz;i++){
                if(i==0)leftView.push_back(q.front()->data);
                Node* n=q.front();
                q.pop();
                if(n->left)q.push(n->left);
                if(n->right)q.push(n->right);
            }
        }
        return leftView;
    }
};
