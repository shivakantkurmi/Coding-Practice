class Solution {
  public:
    int getEdgeCount(vector<vector<int>> &adj, vector<bool> &visited, int V, int startNode){
        int edgeCount = 0;
        queue<int> q;
        q.push(startNode);
        visited[startNode] = true;
        while(!q.empty()){
            int node = q.front();
            q.pop();

            edgeCount += adj[node].size();            
            for(int neigh: adj[node]){
                if(visited[neigh])continue;
                q.push(neigh);
                visited[neigh] = true;
            }
        }
        return (edgeCount/2);
    }
    int countEdges(vector<vector<int>> &adj) {
        int totalEdgeCount = 0, V = adj.size();
        vector<bool> visited(V, false);
        for(int node=0;node<V;node++){
            if(!visited[node])
                totalEdgeCount += getEdgeCount(adj, visited, V, node);
        }
        return totalEdgeCount;
    }
};
