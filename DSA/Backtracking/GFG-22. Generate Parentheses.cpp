class Solution {
    vector<string> ans;
    void generate(int n, int open, int close, string s){
        if(s.length() == 2 * n){
            ans.push_back(s);
            return;
        }
        if(open < n)
            generate(n, open + 1, close, s + '(');

        if(close < open) //as you can only add a closing parentheses when there are more open parentheses on left
            generate(n, open, close + 1, s + ')');
    }

public:
    vector<string> generateParenthesis(int n) {
        generate(n, 0, 0, "");
        return ans;
    }
};


//Time complexity: O(Cn​ × n), where Cn​ is the nth Catalan number.
//cn= (2n)!/(n+1)!(n)!
