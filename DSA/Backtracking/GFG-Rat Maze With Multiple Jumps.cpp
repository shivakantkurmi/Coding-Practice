class Solution {
public:
    vector<vector<int>> shortestDist(vector<vector<int>>& mat) {
        int n = mat.size();

        if (n == 1)
            return {{1}};

        vector<vector<int>> ans(n, vector<int>(n, 0));
        vector<vector<bool>> bad(n, vector<bool>(n, false));

        function<bool(int, int)> dfs = [&](int i, int j) {
            if (i == n - 1 && j == n - 1) {
                ans[i][j] = 1;
                return true;
            }

            if (bad[i][j] || mat[i][j] == 0)
                return false;

            ans[i][j] = 1;

            // smaller jumps first
            for (int jump = 1; jump <= mat[i][j]; jump++) {

                // right first
                int nj = j + jump;
                if (nj < n && ans[i][nj] == 0) {
                    if (dfs(i, nj))
                        return true;
                }

                // then down
                int ni = i + jump;
                if (ni < n && ans[ni][j] == 0) {
                    if (dfs(ni, j))
                        return true;
                }
            }

            ans[i][j] = 0;
            bad[i][j] = true;
            return false;
        };

        if (dfs(0, 0))
            return ans;

        return {{-1}};
    }
};
