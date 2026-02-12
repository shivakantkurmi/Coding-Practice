class Solution {
  public:
    bool canPair(vector<int> &arr, int k) {
        // Code here.
        int n=arr.size();
        if((n&1)==1)return 0;
        vector<int> mp(k,0);
        for(int &i:arr){
            i%=k;
            mp[i]++;
        }
           if(mp[0]%2!=0)return 0;
           for(int i=1;i<k;i++){
               if(2*i==k && mp[i]%2!=0) return 0;
               else if(mp[i]!=mp[k-i]) return 0;
           }
        return 1;
    }
};
