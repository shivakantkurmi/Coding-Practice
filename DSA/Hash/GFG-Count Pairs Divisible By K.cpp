class Solution {
  public:
    int countKdivPairs(vector<int>& arr, int k) {
        // code here
        unordered_map<int,int> mp;
        int ans=0;
        for(int i:arr){
            int x=i%k; //no negative numbers
            int need=(k-x)%k;
            if(mp.find(need)!=mp.end())ans+=mp[need];
            mp[x]++;
        }
        return ans;
        
    }
};
