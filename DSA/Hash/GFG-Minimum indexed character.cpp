class Solution {
  public:
    int minIndexChar(string &s1, string &s2) {
        //  code here
        vector<int> freq(26,0);
        for(char c:s2){
            freq[c-'a']++;
        }
        for(int i=0;i<s1.length();i++){
            if(freq[s1[i]-'a']>0)return i;
        }
        return -1;
    }
};
