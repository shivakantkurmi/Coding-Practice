/*
class Node
{
    int data;
    Node* left;
    Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};
*/

class Solution {
  public:
    vector<int> preOrder(Node* root) {
        // code here
        vector<int> ans;
        if(root==nullptr) return ans;
        
        stack<Node*> st;
        st.push(root);
        while(!st.empty()){
            Node* t= st.top();
            ans.push_back(t->data);
            st.pop();
            if(t->right!=NULL)st.push(t->right);
            if(t->left!=NULL)st.push(t->left);
        }
        return ans;
    }
};
