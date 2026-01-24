class Solution {
public:
    int minPairSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int i=0,j=nums.size()-1;
        int minmax=INT_MIN;
        while(i<j){
            int temp=nums[i]+nums[j];
            if(minmax<temp)minmax=temp;
            i++,j--;
        }
        return minmax;
    }
};
