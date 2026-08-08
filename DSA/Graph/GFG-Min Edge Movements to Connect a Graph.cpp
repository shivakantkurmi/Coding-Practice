class DSU {
public:
    vector<int>parent, rank;
    DSU(int n) {
        parent.resize(n);
        rank.resize(n, 0);
        for (int i = 0; i<n; i++)parent[i] = i;
    }
    int findParent(int x) {
        return parent[x] = parent[x] == x ? x : findParent(parent[x]);
    }
    bool unionFind(int x, int y) {
        int xSet = findParent(x), ySet = findParent(y);
        if (xSet == ySet)return false;
        rank[xSet] < rank[ySet] ? parent[xSet] = ySet : parent[ySet] = xSet;
        rank[xSet] += rank[xSet] == rank[ySet];
        return true;
    }
};

class Solution {
    public:
    int minEdgesReq(int n, vector<vector<int>> & edges) {
        // code here
        DSU dsu(n);
        int cnt = 0;
        for (auto it : edges) {
            if (dsu.unionFind(it[0], it[1]))continue;
            cnt++;
        }
        unordered_set<int>st;
        for (int i = 0; i<n; i++) {
            st.insert(dsu.findParent(i));
        }
        if (st.size() - 1 > cnt)return - 1;
        return st.size() - 1;
    }
};
