class Solution {
public:
    long long countSubstring(string &s) {
        int n = s.size();
        vector<long long> mp(2 * n + 5, 0);

        int pref = 0;
        long long curr = 0;
        long long ans = 0;

        mp[n] = 1;

        for (char c : s) {
            if (c == '1') {
                curr += mp[pref + n];
                pref++;
            } else {
                pref--;
                curr -= mp[pref + n];
            }
            mp[pref + n]++;
            ans += curr;
        }

        return ans;
    }
};
