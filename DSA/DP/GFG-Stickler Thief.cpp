class Solution {
  public:
    int findMaxSum(vector<int>& nums) {
        // code here
        int n=nums.size();
        int prev2=0,prev1=nums[0];
        for(int i=1;i<n;i++){
            int ans=max(prev2+nums[i],prev1);
            prev2=prev1;
            prev1=ans;
        }
        return prev1;
    }
};
