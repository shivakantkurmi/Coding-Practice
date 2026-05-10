class Solution {
  public:
    
    string solve(string s) {
        string ans = "";
        int n = s.length();

        int i = 0;

        while(i < n) {
            int j = i + 1;

            while(j < n && s[i] == s[j]) {
                j++;
            }

            if(j == i + 1) {
                ans.push_back(s[i]);
            }

            i = j;
        }

        if(ans.length() == s.length()) {
            return ans;
        }

        return solve(ans);
    }

    string removeUtil(string &s) {
        return solve(s);
    }
};
