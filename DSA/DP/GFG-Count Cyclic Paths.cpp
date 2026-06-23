class Solution {
    static const int MOD = 1000000007;

    // Recursion
    long long solveRec(int n, int pos) {
        if (n == 0) return (pos == 0);

        long long ans = 0;

        if (pos == 0) {
            ans = (solveRec(n - 1, 1) +
                   solveRec(n - 1, 2) +
                   solveRec(n - 1, 3)) % MOD;
        } else {
            for (int nxt = 0; nxt < 4; nxt++) {
                if (nxt != pos)
                    ans = (ans + solveRec(n - 1, nxt)) % MOD;
            }
        }

        return ans;
    }

    // Memoization
    long long solveMem(int n, int pos, vector<vector<long long>>& dp) {
        if (n == 0) return (pos == 0);

        if (dp[n][pos] != -1)
            return dp[n][pos];

        long long ans = 0;

        if (pos == 0) {
            ans = (solveMem(n - 1, 1, dp) +
                   solveMem(n - 1, 2, dp) +
                   solveMem(n - 1, 3, dp)) % MOD;
        } else {
            for (int nxt = 0; nxt < 4; nxt++) {
                if (nxt != pos)
                    ans = (ans + solveMem(n - 1, nxt, dp)) % MOD;
            }
        }

        return dp[n][pos] = ans;
    }

    // Tabulation
    int solveTab(int N) {
        vector<vector<long long>> dp(N + 1, vector<long long>(4, 0));

        dp[0][0] = 1;

        for (int i = 1; i <= N; i++) {
            dp[i][0] = (dp[i - 1][1] + dp[i - 1][2] + dp[i - 1][3]) % MOD;
            dp[i][1] = (dp[i - 1][0] + dp[i - 1][2] + dp[i - 1][3]) % MOD;
            dp[i][2] = (dp[i - 1][0] + dp[i - 1][1] + dp[i - 1][3]) % MOD;
            dp[i][3] = (dp[i - 1][0] + dp[i - 1][1] + dp[i - 1][2]) % MOD;
        }

        return dp[N][0];
    }

public:
    long long countPaths(int N) {

        // Recursion
        // return solveRec(N, 0);

        // Memoization
        // vector<vector<long long>> dp(N + 1, vector<long long>(4, -1));
        // return solveMem(N, 0, dp);

        // Tabulation
        return solveTab(N);
    }
};
