/*
class Node {
public:
    int data;
    Node* left;
    Node* right;
    Node* nextRight;

    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
        nextRight = nullptr;
    }
};

*/

class Solution {
  public:
    Node* connect(Node* root) {
        // code here
        if(!root) return root;
        Node* temp=root;
        queue<Node*> q;
        q.push(root);
        while(!q.empty()){
            int s=q.size();
            Node* prev=q.front();
            for(int i=0;i<s;i++){
                Node* curr=q.front();
                q.pop();
                if(i==0) prev=curr;
                if(prev!=curr) prev->nextRight=curr,prev=prev->nextRight;
                if(curr->left)q.push(curr->left);
                if(curr->right) q.push(curr->right);
            }
        }
        return root;
    }
};
