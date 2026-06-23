class Solution {
    int solveRec(int n, int x, int y, int z) {
        if (n == 0) return 0;
        if (n < 0) return INT_MIN;

        return max({
            solveRec(n - x, x, y, z) + 1,
            solveRec(n - y, x, y, z) + 1,
            solveRec(n - z, x, y, z) + 1
        });
    }

    int solveMem(int n, int x, int y, int z, vector<int>& dp) {
        if (n == 0) return 0;
        if (n < 0) return INT_MIN;

        if (dp[n] != -1) return dp[n];

        return dp[n] = max({
            solveMem(n - x, x, y, z, dp) + 1,
            solveMem(n - y, x, y, z, dp) + 1,
            solveMem(n - z, x, y, z, dp) + 1
        });
    }

    int solveTab(int n, int x, int y, int z) {
        vector<int> dp(n + 1, INT_MIN); //if you change INT_MIN to -1 then in for loop you always have to verify if after cutting that segment dp is not -1 like in if comdition it will be look like if(i-x>=0 && dp[i-1]!=-1)
        dp[0] = 0;

        for (int i = 1; i <= n; i++) {
            if (i - x >= 0)
                dp[i] = max(dp[i], dp[i - x] + 1);

            if (i - y >= 0)
                dp[i] = max(dp[i], dp[i - y] + 1);

            if (i - z >= 0)
                dp[i] = max(dp[i], dp[i - z] + 1);
        }

        return max(0, dp[n]);
    }

public:
    int maximizeTheCuts(int n, int x, int y, int z) {

        // Recursion
        // return max(0, solveRec(n, x, y, z));

        // Memoization
        // vector<int> dp(n + 1, -1);
        // return max(0, solveMem(n, x, y, z, dp));

        // Tabulation
        return solveTab(n, x, y, z);
    }
};
