class Solution {
  public:
    vector<int> bfs(vector<vector<int>> &adj) {
        // code here
        int V=adj.size();
        vector<int> ans;
        vector<bool> visited(V,0);
        queue<int> q;
        q.push(0);
        visited[0]=true;
        while(!q.empty()){
            int node=q.front();
            q.pop();
            ans.push_back(node);
            for(int i:adj[node]){
                if(visited[i]==false){
                    q.push(i);
                    visited[i]=true;
                }
            }
        }
        return ans;
    }
};
