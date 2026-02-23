class Solution {
public:
    bool hasAllCodes(string s, int k) {
        unordered_map<string,int>mp;
        for(int i=0;i<=s.size();i++){
            if(i>=k){
                mp[s.substr(i-k,k)]++;
            }
        }
        if(mp.size()==pow(2,k))return true;
        return false;
    }
};
