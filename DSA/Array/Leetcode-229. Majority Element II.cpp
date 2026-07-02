class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int candidate1=0,candidate2=0;
        int vote1=0,vote2=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(nums[i] == candidate1)
                vote1++;
            else if(nums[i] == candidate2)
                vote2++;
            else if(vote1 == 0){
                candidate1 = nums[i];
                vote1 = 1;
            }
            else if(vote2 == 0){
                candidate2 = nums[i];
                vote2 = 1;
            }
            else{
                vote1--;
                vote2--;
            }
        }
        int f1=0,f2=0;
        for(int i:nums){
            if(i==candidate1)f1++;
            else if(i==candidate2)f2++;
        }
        vector<int> ans;

        if (f1 > n / 3)
            ans.push_back(candidate1);

        if (candidate2 != candidate1 && f2 > n / 3)
            ans.push_back(candidate2);

        return ans;
    }
};
