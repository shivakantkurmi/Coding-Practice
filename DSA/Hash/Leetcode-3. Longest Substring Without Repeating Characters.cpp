class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<int,int>ch;
        int left=0,n=s.size();
        int ans=0;
        for(int i=0;i<n;i++){
            int v=s[i]-'a';
            if(ch[v]==1){
                while(left<i && ch[v]==1){
                    ch[s[left]-'a']--;
                    left++;
                }
            }
            ch[v]++;
            ans=max(ans,i-left+1);
        }
        return ans;
    }
};
