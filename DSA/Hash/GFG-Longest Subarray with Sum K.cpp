class Solution {
  public:
    int longestSubarray(vector<int>& arr, int k) {
        // code here
        unordered_map<int,int> mp;
        int n=arr.size(),tsum=0,ans=0;
        for(int i=0;i<n;i++){
            tsum+=arr[i];
            if(tsum==k) ans=max(ans,i+1);
            int target=tsum-k;
            if(mp.find(target)!=mp.end()){
                ans=max(ans,i-mp[target]);
            }
            if(mp.find(tsum) == mp.end()) {
                mp[tsum] = i;
            }

        }
        return ans;
    }
};
