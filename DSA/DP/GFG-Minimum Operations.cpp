// class Solution {
//   public:

//     int minOperation(int n) {
//         int ans = 0;
//         while(n > 0){
//             if(n % 2 == 0)
//                 n /= 2;
//             else
//                 n--;
//             ans++;
//         }
//         return ans;
//     }
// };

class Solution {
  public:
    int minOperation(int n) {
        vector<int> dp(n + 1);
        dp[0] = 0;
        for(int i = 1; i <= n; i++) {
            dp[i] = 1 + dp[i - 1];
            if(i % 2 == 0) {
                dp[i] = min(dp[i], 1 + dp[i / 2]);
            }
        }
        return dp[n];
    }
};
