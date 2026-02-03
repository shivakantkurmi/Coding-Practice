class Solution {
public:
    bool isTrionic(vector<int>& nums) {
        int p=-1,q=0;
        for(int i=0;i<nums.size()-1;i++){
            if(nums[i]==nums[i+1])return false;
            if(p==-1 && nums[i]>nums[i+1])p=i;
            else if(p!=-1 && !q && nums[i]<nums[i+1])q=i;
            else if(p!=-1 && q && nums[i]>nums[i+1])return false;
        }
        // cout<<p<<" "<<q;
        if(p<1 || q==0)return false;
        return true;
    }
};
