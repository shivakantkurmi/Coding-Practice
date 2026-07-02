class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector<int> f1(26,0);
        vector<int> f2=f1;
        for(char c:s1)f1[c-'a']++;
        int len=s1.size();
        for(int i=0;i<s2.size();i++){

            f2[s2[i]-'a']++;

            if(i>=len)
                f2[s2[i-len]-'a']--;

            if(i>=len-1 && f1==f2)
                return true;
        }
        return false;
    }
};
