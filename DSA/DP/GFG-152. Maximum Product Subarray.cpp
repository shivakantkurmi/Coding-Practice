class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int minProd=nums[0],maxProd=nums[0],ans=nums[0];
        for(int x=1;x<nums.size();x++){
            int i=nums[x];
            int t=maxProd;
            maxProd=max({i,t*i,minProd*i});
            minProd=min({i,t*i,minProd*i});
            ans=max(ans,maxProd);
        }
        return ans;
    }
};
