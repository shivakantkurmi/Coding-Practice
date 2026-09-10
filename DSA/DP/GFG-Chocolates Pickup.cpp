class Solution {
    int solve(int row, int col1, int col2,
              vector<vector<int>>& mat,
              vector<vector<vector<int>>>& dp) {

        int n = mat.size();
        int m = mat[0].size();

        if (col1 < 0 || col1 >= m || col2 < 0 || col2 >= m)
            return INT_MIN;

        if (row == n)
            return 0;

        if (dp[row][col1][col2] != -1)
            return dp[row][col1][col2];

        int curr;

        if (col1 == col2)
            curr = mat[row][col1];
        else
            curr = mat[row][col1] + mat[row][col2];

        int ans = INT_MIN;

        for (int d1 = -1; d1 <= 1; d1++) {
            for (int d2 = -1; d2 <= 1; d2++) {

                ans = max(ans,
                    curr + solve(row + 1,
                                 col1 + d1,
                                 col2 + d2,
                                 mat,
                                 dp));
            }
        }

        return dp[row][col1][col2] = ans;
    }

public:
    int maxChocolate(vector<vector<int>>& grid) {

        int n = grid.size();
        int m = grid[0].size();

        vector<vector<vector<int>>> dp(
            n,
            vector<vector<int>>(m,
                vector<int>(m, -1)
            )
        );

        return solve(0, 0, m - 1, grid, dp);
    }
};
