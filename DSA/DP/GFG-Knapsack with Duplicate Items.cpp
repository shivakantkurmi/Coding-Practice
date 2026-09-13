class Solution {
  public:
    int knapSack(vector<int>& val, vector<int>& wt, int capacity) {
        // code here
        //this is unbounded 0/1 knapsack
        
        //space optimized dp
        int n=wt.size();
        vector<int> dp(capacity+1,0);
        dp[0]=0;
        
        for(int i=0;i<n;i++){
            for (int w = wt[i]; w <= capacity; w++){//for bounded use backward loop
                dp[w] = max(dp[w], dp[w - wt[i]] + val[i]);
            }
        }
        return dp[capacity];
        
    }
};
