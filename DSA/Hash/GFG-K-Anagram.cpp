class Solution {
  public:
    bool areKAnagrams(string &s1, string &s2, int k) {
        // code here
        int n1=s1.size(),n2=s2.size();
        if(n1!=n2)return false;
        vector<int> freq(26,0);
        for(char c:s1)freq[c-'a']++;
        for(char c:s2){
            int x=c-'a';
            if(freq[x]>0)freq[x]--;
            else k--;
            if(k<0) return 0;
        }
        return true;
    }
};
