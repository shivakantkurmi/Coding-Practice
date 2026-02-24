class Solution {
  public:
    int equalSumSpan(vector<int> &a1, vector<int> &a2) 
    {
        int n=a1.size();
        unordered_map<int,int> mp;
        int ans=0,sum=0;
        mp[0]=-1;
        for(int i=0;i<n;i++)
        {
            sum+=a1[i]-a2[i];
            if(mp.find(sum)!=mp.end()) ans=max(ans,i-mp[sum]);
            else mp[sum]=i;
        }
        return ans;
    }
};
