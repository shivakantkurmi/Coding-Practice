/* The Node structure is
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/
class Solution {
    void solve(Node* root, vector<int> &in){
        if(!root)return ;
        solve(root->left,in);
        in.push_back(root->data);
        solve(root->right,in);
    }
    
    void buildBST(Node* root,int &i, vector<int> &in){
        if(!root)return;
        buildBST(root->left,i,in);
        root->data=in[i++];
        buildBST(root->right,i,in);
    }
    
  public:
    Node *binaryTreeToBST(Node *root) {
        // code here
        vector<int> in;
        solve(root,in);
        
        sort(in.begin(),in.end());
        
        int i=0;
        buildBST(root,i,in);
        return root;
    }
};
