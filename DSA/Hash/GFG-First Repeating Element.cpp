class Solution {
  public:
    int firstRepeated(vector<int> &arr) {
        // code here
        unordered_map<int,int> mp;
        int n=arr.size();
        int ans=INT_MAX;
        for(int i=0;i<n;i++){
            if(mp.find(arr[i])!=mp.end()) ans=min(ans,mp[arr[i]]);
            mp[arr[i]]=i+1;
        }
        return ans==INT_MAX?-1:ans;
    }
};
