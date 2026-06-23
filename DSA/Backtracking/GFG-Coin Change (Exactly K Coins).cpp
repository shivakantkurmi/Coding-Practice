class Solution {
    bool solve(int idx, int numCoins, int sum,
               int N, int K, int target,
               vector<int>& coins,
               vector<vector<vector<int>>>& dp) {
    
        if (sum == target)
            return numCoins == K;
    
        if (idx == N || numCoins > K || sum > target)
            return false;
    
        if (dp[idx][numCoins][sum] != -1)
            return dp[idx][numCoins][sum];
    
        bool take = solve(idx,
                          numCoins + 1,
                          sum + coins[idx],
                          N, K, target,
                          coins, dp);
    
        bool notTake = solve(idx + 1,
                             numCoins,
                             sum,
                             N, K, target,
                             coins, dp);
    
        return dp[idx][numCoins][sum] = take || notTake;
    }
    public:
        bool makeChanges(int K, int target, vector<int>& coins) {
            int N=coins.size();
            vector<vector<vector<int>>> dp(
                N,
                vector<vector<int>>(K + 1,
                vector<int>(target + 1, -1)));
        
            return solve(0, 0, 0, N, K, target, coins, dp);
        }
};
