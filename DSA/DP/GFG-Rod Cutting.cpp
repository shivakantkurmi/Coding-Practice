class Solution {
public:
    int cutRod(vector<int> &price) {
        int n = price.size();
        //its also a question of unobounded 0/1 knapsack

        vector<int> dp(n + 1, 0);

        for (int i = 1; i <= n; i++) {

            // i = length of current piece
            for (int j = i; j <= n; j++) {

                dp[j] = max(
                    dp[j],
                    dp[j - i] + price[i - 1]
                );
            }
        }

        return dp[n];
    }
};
