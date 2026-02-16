//isogram means each character only once
class Solution {
  public:
    bool isIsogram(string& s) {
        //  code here
        vector<int> freq(26,0);
        for(char c:s){
            freq[c-'a']++;
            if(freq[c-'a']>1)return 0;
        }
        return true;
    }
};
