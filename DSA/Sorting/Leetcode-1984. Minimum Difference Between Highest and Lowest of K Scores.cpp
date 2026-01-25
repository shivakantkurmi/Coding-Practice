class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        int n=nums.size();
        if (n==1 || k==1){
            return 0;
        }
       
        sort(nums.begin(),nums.end());
        int mindiff=INT_MAX;
        k--;
       
        for (int i=0;k<n;i++){
            mindiff=min(mindiff,nums[k]-nums[i]);
            k++;
        }
       
       return mindiff;
    }
};
