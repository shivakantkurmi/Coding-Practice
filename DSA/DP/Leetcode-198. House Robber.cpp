class Solution {
public:
    //space optimize dp
    int rob(vector<int>& nums) {
        int n=nums.size();
        int prev2=0,prev1=nums[0];
        for(int i=1;i<n;i++){
            int ans=max(prev2+nums[i],prev1);
            prev2=prev1;
            prev1=ans;
        }
        return prev1;
    }

    //using dp array
    // int rob(vector<int>& nums) {
    //     int n=nums.size();
    //     vector<int> dp(n,0);
    //     if(n==1) return nums[0];
    //     dp[0]=nums[0];
    //     dp[1]=max(nums[0],nums[1]);
    //     for(int i=2;i<n;i++){
    //         dp[i]=max(dp[i-2]+nums[i],dp[i-1]);
    //     }
    //     return dp[n-1];
    // }
};
