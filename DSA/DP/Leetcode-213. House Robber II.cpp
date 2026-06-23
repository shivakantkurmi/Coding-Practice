class Solution {
    int solve(int start , int end, vector<int>& nums){
        int prev2=0,prev1=nums[start];
        for(start+=1;start<end;start++){
            int ans=max(prev2+nums[start],prev1);
            prev2=prev1;
            prev1=ans;
        }
        return prev1;
    }
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==1) return nums[0];
        int res1=solve(0,n-1,nums);
        int res2=solve(1,n,nums);
        return max(res1,res2);
    }
};
