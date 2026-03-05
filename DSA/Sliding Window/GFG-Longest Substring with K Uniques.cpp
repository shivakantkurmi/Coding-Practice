class Solution {
  public:
    int longestKSubstr(string &s, int k) {
        // code here
        int dist=0;
        unordered_map<char,int>mp;
        int l=0,ans=-1;
        for(int i=0;i<s.length();i++){
            if(++mp[s[i]]==1)dist++;
            while(dist>k){
                if(--mp[s[l]]==0)dist--;
                l++;
            }
            if(dist==k) ans=max(ans,i-l+1);
        }
        return ans;
    }
};
