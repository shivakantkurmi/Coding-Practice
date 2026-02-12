class Solution {
  public:
    string firstRepChar(string s) {
        // code here.
        string ans="";
        vector<int>freq(26,0);
        for(char c: s){
            freq[c-'a']++;
            if(freq[c-'a']>1){
                ans+=c;
                return ans;
            }
        }
        return "-1";
    }
};
