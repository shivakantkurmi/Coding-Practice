class Solution {
public:
    int findWays(int n) {
        if(n % 2) return 0;
        int x = n / 2;
        
        vector<long long> dp(x+1, 0);
        dp[0] = dp[1] = 1;
        
        for(int i = 2; i <= x; i++){
            for(int j = 0; j < i; j++){
                dp[i] += dp[j] * dp[i-j-1];
            }
        }
        
        return dp[x];
    }
};


//2nd way to use catalan Number which is used to calculate counting balanced parentheses / handshakes / BSTs.
//  c(n)=2n!/(n+1)!*(n)!
// recursive : 
/*
class Solution {
  private:
    long long dp[1001];

    long long catalan(int n){
        if(n <= 1) return 1;
        if(dp[n] != -1) return dp[n];

        long long ans = 0;
        for(int i = 0; i < n; i++){
            ans += catalan(i) * catalan(n - 1 - i);
        }
        return dp[n] = ans;
    }

  public:
    int findWays(int n) {
        if(n % 2) return 0;

        memset(dp, -1, sizeof(dp));   

        int x = n / 2;
        return catalan(x);
    }
};
*/






//3rd way 
/*
class Solution {
  private:
    long long dp[1001];

    long long catalan(int n){
        if(n <= 1) return 1;
        if(dp[n] != -1) return dp[n];

        long long ans = 0;
        for(int i = 0; i < n; i++){
            ans += catalan(i) * catalan(n - 1 - i);
        }
        return dp[n] = ans;
    }

  public:
    int findWays(int n) {
        if(n % 2) return 0;

        memset(dp, -1, sizeof(dp));   

        int x = n / 2;
        return catalan(x);
    }
};
*/
