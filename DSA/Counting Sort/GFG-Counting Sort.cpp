class Solution {
  public:
    string countSort(string s) {
        // code here
        vector<int>count(26);
        for(char c:s) count[c-'a']++;
        int idx=0;
        for(int i=0;i<26;i++){
            while(count[i]--){
                s[idx++]=(char)('a'+i);
            }
        }
        return s;
    }
};
