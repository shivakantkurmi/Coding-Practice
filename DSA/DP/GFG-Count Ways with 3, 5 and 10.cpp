class Solution {
  public:
    int countWays(int n) {
        vector<int> coins = {10,5,3};
        vector<int> dp(n+1,0);
        dp[0]=1;
        for(int c : coins){
            for(int i=c;i<=n;i++){
                dp[i]+=dp[i-c];
            }
        }
        return dp[n];
    }
};
