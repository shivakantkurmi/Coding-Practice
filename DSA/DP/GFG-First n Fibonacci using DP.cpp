class Solution {
    const int MOD=1e9+7;
  public:
    vector<int> fibonacciNumbers(int n) {
        // code here
        vector<int> ans(n+1,0);
        ans[1]=1;
        for(int i=2;i<=n;i++){
           ans[i]=(ans[i-1]+ans[i-2])%MOD;
        }
        return ans;
    }
};
