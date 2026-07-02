class Solution {
public:
    int mostFrequentEven(vector<int>& nums) {
        unordered_map<int,int> mp;
        for(int i:nums)mp[i]++;
        int maxF=INT_MIN,ans=INT_MAX;
        for(auto v: mp){
            if(v.first%2==0){
                if(v.second>maxF && v.first%2==0)maxF=v.second,ans=v.first;
                else if(v.second==maxF)ans=min(ans,v.first);
            }
        }
        return ans==INT_MAX?-1:ans;
    }
};
