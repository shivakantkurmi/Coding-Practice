class Solution {
public:
    bool checkOnesSegment(string s) {
        bool f=0;
        for(int i=1;i<s.size();i++){
            if(s[i]=='0') f=1;
            else if(f)return 0;
        }
        return 1;
    }
};
