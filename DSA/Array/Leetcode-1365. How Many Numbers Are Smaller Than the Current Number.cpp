class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        int maxe=*max_element(nums.begin(),nums.end());
        vector<int> count(maxe+1,0);
        for(int i:nums)count[i]++;
        for(int i=1;i<maxe;i++){
            //make coount as prefix sum array
            count[i]+=count[i-1];
        }
        for(int i=0;i<nums.size();i++){
            if(nums[i]) nums[i]=count[nums[i]-1];
        }
        return nums;
    }
};
