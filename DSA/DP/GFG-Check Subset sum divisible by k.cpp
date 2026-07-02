// class Solution {
//     vector<vector<int>> dp;

//     bool solve(int idx, int k, int n, int sum, vector<int>& arr) {
//         if (sum != 0 && sum % k == 0)
//             return true;

//         if (idx == n)
//             return false;

//         if (dp[idx][sum] != -1)
//             return dp[idx][sum];

//         return dp[idx][sum] =
//             solve(idx + 1, k, n, sum + arr[idx], arr) ||
//             solve(idx + 1, k, n, sum, arr);
//     }

// public:
//     bool divisibleByK(vector<int>& arr, int k) {
//         int total = 0;
//         for (int x : arr)
//             total += x;

//         dp.assign(arr.size(), vector<int>(total + 1, -1));

//         return solve(0, k, arr.size(), 0, arr);
//     }
// };



//TLE
// class Solution {
// public:
//     bool divisibleByK(vector<int>& arr, int k) {

//         int n = arr.size();
//         vector<vector<bool>> dp(n + 1, vector<bool>(k, false));

//         for (int i = 1; i <= n; i++) {

//             int rem = ((arr[i - 1] % k) + k) % k;

//             // Start a new subset
//             dp[i][rem] = true;

//             for (int r = 0; r < k; r++) {

//                 // Don't take current element
//                 if (dp[i - 1][r])
//                     dp[i][r] = true;

//                 // Take current element
//                 if (dp[i - 1][r])
//                     dp[i][(r + rem) % k] = true;
//             }
//         }

//         return dp[n][0];
//     }
// };





//space optimized DP 
class Solution {
public:
    bool divisibleByK(vector<int>& arr, int k) {
        vector<bool> dp(k, false);
        for (int x : arr) {
            vector<bool> next = dp;
            int rem = ((x % k) + k) % k;
            next[rem] = true;
            for (int r = 0; r < k; r++) {
                if (dp[r])
                    next[(r + rem) % k] = true;
            }
            dp = next;
        }

        return dp[0];
    }
};
