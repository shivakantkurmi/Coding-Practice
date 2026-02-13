class Solution {
  public:
    char firstRep(string s) {
        // code here.
        int freq[26]={0};
        for(char ch:s)freq[ch-'a']++;
        for(char ch:s){
            if(freq[ch-'a']>1)return ch;
        }
        return '#';
    }
};
