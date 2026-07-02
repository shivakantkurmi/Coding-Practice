// //Kadane Algo
// class Solution {
// public:
//     int maxSubArray(vector<int>& nums) {
//         int cs=0,ms=INT_MIN;
//         for(int i=0;i<nums.size();i++){
//             cs+=nums[i];
//             ms=max(cs,ms);
//             if(cs<0) cs=0;
//         }
//         return ms;
//     }
// };


// //TLE
// class Solution {
// public:
//     int maxSubArray(vector<int>& nums) {    
//         return solve(nums, 0, false);
//     }
//     int solve(vector<int>& A, int i, bool mustPick) {
// 		// our subarray must contain atleast 1 element. If mustPick is false at end means no element is picked and this is not valid case
//         if(i >= size(A)) return mustPick ? 0 : -1e5;       
//         if(mustPick)
//             return max(0, A[i] + solve(A, i+1, true));                  // either stop here or choose current element and recurse
//         return max(solve(A, i+1, false), A[i] + solve(A, i+1, true));   // try both choosing current element or not choosing
//     }
// };

//memoization
// class Solution {
// public:
//     int maxSubArray(vector<int>& nums) {    
//         vector<vector<int>> dp(2, vector<int>(size(nums), -1));
//         return solve(nums, 0, false, dp);
//     }
//     int solve(vector<int>& A, int i, bool mustPick, vector<vector<int>>& dp) {
//         if(i >= size(A)) return mustPick ? 0 : -1e5;
//         if(dp[mustPick][i] != -1) return dp[mustPick][i];
//         if(mustPick)
//             return dp[mustPick][i] = max(0, A[i] + solve(A, i+1, true, dp));
//         return dp[mustPick][i] = max(solve(A, i+1, false, dp), A[i] + solve(A, i+1, true, dp));
//     }
// };

// //tabulization
// class Solution {
// public:
//     int maxSubArray(vector<int>& nums) {
//         vector<vector<int>> dp(2, vector<int>(size(nums)));
//         dp[0][0] = dp[1][0] = nums[0];
//         for(int i = 1; i < size(nums); i++) {
//             dp[1][i] = max(nums[i], nums[i] + dp[1][i-1]);
//             dp[0][i] = max(dp[0][i-1], dp[1][i]);
//         }
//         return dp[0].back();
//     }
// };


//divide and conquer
class Solution {
public:
    vector<int> pre, suf;
    int maxSubArray(vector<int>& nums) {
        pre = suf = nums;
        for(int i = 1; i < size(nums); i++)  pre[i] += max(0, pre[i-1]);
        for(int i = size(nums)-2; ~i; i--)   suf[i] += max(0, suf[i+1]);
        return maxSubArray(nums, 0, size(nums)-1);
    }
    int maxSubArray(vector<int>& A, int L, int R){
        if(L == R) return A[L];
        int mid = (L + R) / 2;
        return max({ maxSubArray(A, L, mid), maxSubArray(A, mid+1, R), pre[mid] + suf[mid+1] });
    }	
};
