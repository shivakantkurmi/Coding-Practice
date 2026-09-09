class Solution {
    map<pair<int,int>, set<string>> memo;

    set<string> solve(int i, int j, string &a, string &b,
                      vector<vector<int>> &dp) {

        if (i == 0 || j == 0) {
            return {""};
        }

        if (memo.count({i, j}))
            return memo[{i, j}];

        set<string> ans;

        if (a[i - 1] == b[j - 1]) {

            set<string> temp = solve(i - 1, j - 1, a, b, dp);

            for (string s : temp) {
                ans.insert(s + a[i - 1]);
            }

        }
        else {

            if (dp[i - 1][j] >= dp[i][j - 1]) {
                set<string> temp = solve(i - 1, j, a, b, dp);

                for (string s : temp)
                    ans.insert(s);
            }

            if (dp[i][j - 1] >= dp[i - 1][j]) {
                set<string> temp = solve(i, j - 1, a, b, dp);

                for (string s : temp)
                    ans.insert(s);
            }
        }

        return memo[{i, j}] = ans;
    }

public:
    vector<string> allLCS(string &s1, string &s2) {

        int n = s1.size();
        int m = s2.size();

        vector<vector<int>> dp(
            n + 1,
            vector<int>(m + 1, 0)
        );

        // LCS length
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {

                if (s1[i - 1] == s2[j - 1])
                    dp[i][j] = 1 + dp[i - 1][j - 1];

                else
                    dp[i][j] = max(dp[i - 1][j],
                                   dp[i][j - 1]);
            }
        }

        memo.clear();

        set<string> ans = solve(n, m, s1, s2, dp);

        return vector<string>(ans.begin(), ans.end());
    }
};
