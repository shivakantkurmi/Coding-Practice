class Solution {
  public:
    virtual int dfs(int n, vector<int> &dp){
      if(n<=1) return 1;
      if(dp[n] != -1) return dp[n];
      
      return dp[n]=(dfs(n-1, dp)+dfs(n-2, dp));
    }
    
    virtual int countWays(int n){
      vector<int> dp(n+1, -1);
      return dfs(n, dp);
    }
};



//this question just follow the recurrance relation of fibonacci series
//f(n)=f(n-1)+f(n-2)
//as at nth step we only have ways that we reach it by one step or 2 step 
int countWays(int n) {
    if (n <= 1) return 1;

    int a = 1, b = 1;

    for (int i = 2; i <= n; i++) {
        int c = a + b;
        a = b;
        b = c;
    }

    return b;
}
