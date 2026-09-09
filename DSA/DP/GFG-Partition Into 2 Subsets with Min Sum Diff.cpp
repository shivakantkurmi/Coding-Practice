// class Solution {
    
//     //this one give TLE
//     // int solve(int idx, int sum1, int sum2, vector<int> &arr,vector<vector<vector<int>>>  &dp){
//     //     if(idx<0)return abs(sum1-sum2);
        
//     //     if(dp[idx][sum1][sum2]!=INT_MAX)return dp[idx][sum1][sum2];
//     //     int v1=solve(idx-1,sum1+arr[idx],sum2,arr,dp);
//     //     int v2=solve(idx-1,sum1,sum2+arr[idx],arr,dp);
//     //     return dp[idx][sum1][sum2]=min(v1,v2);
//     // }
    
    
//     //this one passes
//     // int solve(int idx,int sum1,vector<int> &arr,int& finalSum, vector<vector<int>>&dp){
//     //     if(idx<0)return abs(sum1 - (finalSum - sum1));
//     //     if(dp[idx][sum1]!=INT_MAX)return dp[idx][sum1];
//     //     int v1=solve(idx-1,sum1+arr[idx],arr,finalSum,dp);
//     //     int v2=solve(idx-1,sum1,arr,finalSum,dp); //when arr[idx] is adding to 2nd partition
        
//     //     return dp[idx][sum1]=min(v1,v2);
//     // }
//   public:
//     int minDifference(vector<int>& arr) {
//         // code here
//         int n=arr.size();
//         int sum=accumulate(arr.begin(),arr.end(),0);
//         // vector<vector<int>> dp(n+1,vector<int>(sum+1,INT_MAX));
//         // return solve(n-1,0,arr,sum,dp);
        
//         if(n==1)return arr[0];
//         vector<vector<int>>dp(n+1,vector<int>(sum+1,INT_MAX));
//         for(int i=1;i<=n;i++){
//             for(int j=1;j<=sum;j++){
//                 dp[i][sum]=dp[i-1]
                
//             }
//         }
        
//     }
// };




// class Solution {
// public:
//     int minDifference(vector<int>& arr) {
//         int n = arr.size();
//         int totalSum = accumulate(arr.begin(), arr.end(), 0);

//         vector<vector<int>> dp(n + 1, vector<int>(totalSum + 1, INT_MAX));

//         // For 0 elements and sum1 = 0
//         dp[0][0] = totalSum;

//         for (int i = 1; i <= n; i++) {
//             for (int sum1 = 0; sum1 <= totalSum; sum1++) {

//                 // Put arr[i-1] in partition 2
//                 if (dp[i - 1][sum1] != INT_MAX) {
//                     dp[i][sum1] = dp[i - 1][sum1];
//                 }

//                 // Put arr[i-1] in partition 1
//                 if (sum1 >= arr[i - 1] &&
//                     dp[i - 1][sum1 - arr[i - 1]] != INT_MAX) {
//                     dp[i][sum1] = dp[i - 1][sum1 - arr[i - 1]];
//                 }
//             }
//         }

//         int ans = INT_MAX;

//         for (int sum1 = 0; sum1 <= totalSum; sum1++) {
//             if (dp[n][sum1] != INT_MAX) {
//                 int sum2 = totalSum - sum1;
//                 ans = min(ans, abs(sum1 - sum2));
//             }
//         }

//         return ans;
//     }
// };




//space optimized
class Solution {
public:
    int minDifference(vector<int>& arr) {
        int totalSum = accumulate(arr.begin(), arr.end(), 0);

        vector<bool> dp(totalSum + 1, false);
        dp[0] = true;

        for (int x : arr) {
            for (int sum = totalSum; sum >= x; sum--) {
                dp[sum] = dp[sum] || dp[sum - x];
            }
        }

        int ans = INT_MAX;

        for (int sum1 = 0; sum1 <= totalSum / 2; sum1++) {
            if (dp[sum1]) {
                ans = min(ans, totalSum - 2 * sum1);
            }
        }

        return ans;
    }
};









// //this one is standard as we can check which values of subsetsum 1 is possible using subset sum dp and can find minimum using totalsum-sum1


//TLE
// class Solution {
// public:
//     int minDifference(vector<int>& arr) {
//         int n = arr.size();
//         int totalSum = accumulate(arr.begin(), arr.end(), 0);

//         vector<vector<bool>> dp(n + 1, vector<bool>(totalSum + 1, false));

//         // Sum 0 is always possible
//         for (int i = 0; i <= n; i++)
//             dp[i][0] = true;

//         for (int i = 1; i <= n; i++) {
//             for (int sum = 1; sum <= totalSum; sum++) {

//                 // Don't take arr[i-1]
//                 dp[i][sum] = dp[i - 1][sum];

//                 // Take arr[i-1]
//                 if (sum >= arr[i - 1])
//                     dp[i][sum] = dp[i][sum] ||
//                                  dp[i - 1][sum - arr[i - 1]];
//             }
//         }

//         int ans = INT_MAX;

//         // sum = sum of first partition
//         for (int sum1 = 0; sum1 <= totalSum; sum1++) {
//             if (dp[n][sum1]) {
//                 int sum2 = totalSum - sum1;
//                 ans = min(ans, abs(sum1 - sum2));
//             }
//         }

//         return ans;
//     }
// };
