class Solution {
public:
    int minOperations(string s) {
        bool f=0,f2=1;
        int ans=0,ans2=0;
        for(auto c:s){
            if(c-'0'!=f)ans++;
            if(c-'0'!=f2)ans2++;
            f=!f;
            f2=!f2;
        }
        return min(ans,ans2);
    }
};
