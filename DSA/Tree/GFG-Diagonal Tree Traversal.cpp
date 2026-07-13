/* A binary tree node
struct Node
{
    int data;
    Node* left, * right;
}; */

class Solution {
    void dfs(Node *u,int dn, map<int,vector<int>>&mp ){
      if(!u) return;
     
     
       mp[dn].push_back(u->data);
      
      
      dfs(u->left,dn+1,mp);
      dfs(u->right,dn,mp);
    }
  public:
    vector<int> diagonal(Node *r) {
        // code here
        map<int,vector<int>>mp; // digonal no, vector;
        vector<int>v;
        dfs(r,0,mp); // root, digonal no, vector
        
        for(auto &p: mp){
            for(int x: p.second){
                v.push_back(x);
            }
        }
        
        return v;
    }
};
