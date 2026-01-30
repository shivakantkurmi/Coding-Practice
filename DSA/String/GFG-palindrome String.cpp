class Solution {
public:
    bool isPalindrome(string& s) {
        // code here
        int i = 0, j = s.length() - 1;
        while (i <= j) {
            if (s[i++] != s[j--]) return false;
        }
        return true;
    }
};
