class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n=nums.size();
        vector<int> ans;
        for(int i=0;i<n;i++){
            if(nums[abs(nums[i])-1]<0){
                ans.push_back(abs(nums[i]));
                break;
            }
            nums[abs(nums[i])-1]*=-1;
        }
        int missing;
        int sum=0;
        for(int i:nums)sum+=abs(i);
        sum-=ans[0];
        int rSum=n*(n+1)/2;
        missing=rSum-sum;
        ans.push_back(missing);
        return ans;
    }
};
