class Solution {
  public:
    string firstNonRepeating(string &s) {
        // code here
        vector<int> freq(26,0);
        string ans="";
        int i=0;
        for(int j=0;j<s.length();j++){
            freq[s[j]-'a']++;
            while(i<=j && freq[s[i]-'a']!=1)i++;
            if(i>j) ans.push_back('#');
            else ans.push_back(s[i]);
        }
        return ans;
    }
};
