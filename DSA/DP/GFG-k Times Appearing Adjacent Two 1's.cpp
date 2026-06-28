class Solution {
  public:
    int mod=1e9+7;
    int solve(int n,int k,int idx,int prev,int adj){
        if(idx>=n){
            return adj==k;
        }
        if(adj > k) return 0;
        if(idx== n-1 && adj==k) return 1;
        if(prev==1){
             return (solve(n,k,idx+1,1,adj+1)%mod + solve(n,k,idx+1,0,adj)%mod)%mod;
        }
        else{
            return (solve(n,k,idx+1,1,adj)%mod + solve(n,k,idx+1,0,adj)%mod)%mod;
        }
    }
    int solveMemo(int n,int k,int idx,int prev,int adj,vector<vector<vector<int>>>& dp){
        if(idx>=n){
            return adj==k;
        }
        if(adj > k) return 0;
        if(dp[idx][prev][adj]!=-1) return dp[idx][prev][adj];
        if(prev==1){
             return dp[idx][prev][adj]= (solveMemo(n,k,idx+1,1,adj+1,dp)%mod + solveMemo(n,k,idx+1,0,adj,dp)%mod)%mod;
        }
        else{
            return dp[idx][prev][adj]= (solveMemo(n,k,idx+1,1,adj,dp)%mod + solveMemo(n,k,idx+1,0,adj,dp)%mod)%mod;
        }
    }
    int solveTab(int n,int k){
        vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(2,vector<int>(k+1,0)));
        for(int prev=0; prev<2; prev++)
                dp[n][prev][k] = 1;

        for (int idx = n - 1; idx >= 1; idx--) {
            for (int prev = 0; prev < 2; prev++) {
                for (int adj = 0; adj <= k; adj++) {
                    if (prev == 1) {
                        // Place 1
                        if (adj + 1 <= k)
                            dp[idx][prev][adj] =(dp[idx][prev][adj] +dp[idx + 1][1][adj + 1]) % mod;
                        // Place 0
                        dp[idx][prev][adj] =(dp[idx][prev][adj] +dp[idx + 1][0][adj]) % mod;
                    }
                    else {
                        // Place 1
                        dp[idx][prev][adj] =(dp[idx][prev][adj] +dp[idx + 1][1][adj]) % mod;

                        // Place 0
                        dp[idx][prev][adj] =(dp[idx][prev][adj] +dp[idx + 1][0][adj]) % mod;
                    }
                }
            }
        }

        return (dp[1][0][0] + dp[1][1][0]) % mod;
    }
    int countStrings(int n, int k) {
        // code here
        // return (solve(n,k,1,0,0)%mod+solve(n,k,1,1,0)%mod)%mod;
        // vector<vector<vector<int>>> dp(n,vector<vector<int>>(2,vector<int>(k+1,-1)));
        // return (solveMemo(n,k,1,0,0,dp)%mod+solveMemo(n,k,1,1,0,dp)%mod)%mod;
        return solveTab(n,k);
    }
};
