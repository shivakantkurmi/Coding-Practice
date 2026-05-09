class Solution {
    vector<string> ans;
    void generate(int n, string s){
        if(n==s.length()){
            ans.push_back(s);
            return;
        }
        generate(n,s+'1');
        if(s.empty() || s.back()!='0') generate(n,s+'0'); // we can add zero if either empty or last one is not 0
    }
public:
    vector<string> validStrings(int n) {
        generate(n,"");
        return ans;
    }
};
