class Solution {
public:
    int noOfChicks(int n) {
        vector<long long> dp(n + 1, 0);

        dp[1] = 1;
        int totalchicks=1;

        for (int i = 2; i <= n; i++) {
            for (int j = 1; j <= min(i , 5); j++) {
                dp[i] += dp[i - j];
            }
            dp[i] *= 2;
            totalchicks+=dp[i];
            if(i>6)totalchicks-=dp[i-6];
        }

        return totalchicks;
    }
};
