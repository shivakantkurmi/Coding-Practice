class Solution {
  public:
    int countSubarray(vector<int>& arr) {
        // code here
        unordered_map<int,int> mp;
        mp[0]=1;
        // if cont subarray using prefix sum then mp[0]=1 , if max subarray then mp[0]=-1
        int t=0;
        for(int &i:arr){
            if(i==0) i=-1;
        }
        int ans=0;
        for(int i:arr){
            t+=i;
            if(mp.find(t)!=mp.end()){
                ans+=mp[t];
            }
            mp[t]++;
        }
        return ans;
    }
};
