class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        int n=nums.size();
        vector<int> ans(n,-1);
        for(int i=0;i<n;i++){
            if(nums[i]==2){
                ans[i]=-1;
            }
            else{
                for(int j=1;j<32;j++){
                    if(nums[i] & (1<<j)) continue;
                    else {
                        int mask=1<<(j-1);
                        mask=~mask;
                        nums[i]=nums[i]&mask;
                        break;
                    }
                }
                ans[i]=nums[i];
            }
            
        }
        return ans;
    }
};
