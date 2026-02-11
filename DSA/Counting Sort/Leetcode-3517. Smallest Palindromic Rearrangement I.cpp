class Solution {
public:
    string smallestPalindrome(string s) {
        vector<int> count(26,0);
        int n=s.size();
        if(n==1)return s;
        for(char c:s)count[c-'a']++;
        string smallpalindrom="";
        char odd;
        for(int i=0;i<26;i++){
                while(count[i]){
                    if(count[i]==1){
                        odd=(char)(i+'a');
                        break;
                    }
                    smallpalindrom.push_back((char)(i+'a'));
                    count[i]-=2;
                }
        }
        string ans=smallpalindrom;
        reverse(smallpalindrom.begin(),smallpalindrom.end());
        if(n%2!=0)ans.push_back(odd);
        ans+=(smallpalindrom);
        return ans;

    }
};
