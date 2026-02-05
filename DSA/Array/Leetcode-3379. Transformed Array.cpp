class Solution {
public:
    vector<int> constructTransformedArray(vector<int>& nums) {
        int n=nums.size();
        vector<int> ans(n,0);
        for(int i=0;i<n;i++){
            if(nums[i]==0) continue;
            else if(nums[i]>0){
                ans[i]=nums[(i+nums[i])%n];
            }
            else{
                int x=i+nums[i];
                ans[i]=nums[((x%n+n)%n)];
            }
        }
        return ans;
    }
};
