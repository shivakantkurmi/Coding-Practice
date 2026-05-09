class Solution {
    vector<string> ans;
    void generate(int n, int open, int close, string s){
        if(s.length()==n){
            ans.push_back(s);
            return;
        }
        if(open<n/2) generate(n,open+1,close,s+'(');
        if(open>close) generate(n,open,close+1,s+')');
    }
  public:
    vector<string> generateParentheses(int n) {
        // code here
        generate(n,0,0,"");
        return ans;
    }
};
