class Solution {
    unordered_map<int, vector<int>> mp;

public:
    bool isValid(int vertex, int color, vector<int>& x) {
        for(auto i : mp[vertex]) {
            if(x[i] == color) return false;
        }
        return true;
    }

    bool solve(int idx, vector<int>& x, int m, int v) {
        if(idx == v) return true;

        for(int i = 1; i <= m; i++) {
            if(isValid(idx, i, x)) {
                x[idx] = i;

                if(solve(idx + 1, x, m, v))
                    return true;

                x[idx] = 0;
            }
        }

        return false;
    }

    bool graphColoring(int v, vector<vector<int>>& edges, int m) {
        for(auto i : edges) {
            mp[i[0]].push_back(i[1]);
            mp[i[1]].push_back(i[0]);
        }

        vector<int> x(v, 0);

        return solve(0, x, m, v);
    }
};
