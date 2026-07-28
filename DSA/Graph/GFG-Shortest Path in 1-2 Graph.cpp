class Cmp {
	public:
	bool operator()(pair<int, int>& p1, pair<int, int>& p2) {
		return p1.second > p2.second;
	}
};

class Solution {
	public:
	int solve(vector<vector<pair<int, int>>>& adj, const int V, const int src, const int dest) {
		
		vector<bool> vis(V, false);
		vector<int> dist(V, INT_MAX);
		
		dist[src] = 0;
		
		priority_queue<pair<int, int>, vector<pair<int, int>>, Cmp> pq;
		pq.push({src, 0});
		
		while (!pq.empty()) {
			pair<int, int> t = pq.top();
			pq.pop();
			
			vis[t.first] = true;
			
			if (dist[t.first] < t.second)
				continue;
			
			for (auto it : adj[t.first])
				if (!vis[it.first] && dist[it.first] > t.second + it.second) {
				dist[it.first] = t.second + it.second;
				pq.push({it.first, t.second + it.second});
			}
		}
		
		return dist[dest];
	}
	int shortestPath(int V, int src, int dest, vector<vector<int>> & edges) {
		
		vector<vector<pair<int, int>> > adj(V);
		
		for (auto it : edges) {
			adj[it[0]].push_back({it[1], it[2]});
			adj[it[1]].push_back({it[0], it[2]});
		}
		
		int dist = solve(adj, V, src, dest);
		
		return dist == INT_MAX ? -1 : dist;
	}
};
