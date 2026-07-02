class Solution {
  public:
    int waysToIncreaseLCSBy1(string &s1, string &s2) {
        // code here
        int N1=s1.size();
        int N2=s2.size();
        vector<vector<int>> dpl(N1 + 1, vector<int> (N2 + 1));
        for (int i = 0; i < N1; ++i) {
            for (int j = 0; j < N2; ++j) {
                dpl[i + 1][j + 1] = s1[i] == s2[j] ? dpl[i][j] + 1 : max(dpl[i + 1][j], dpl[i][j + 1]);
            }
        }
        //dpl[i][j] == lcs(s1[0 to i - 1], s2[0 to j - 1])
        
        vector<vector<int>> dpr(N1 + 1, vector<int> (N2 + 1));
        for (int i = N1; i; --i) {
            for (int j = N2; j; --j) {
                dpr[i - 1][j - 1] = s1[i - 1] == s2[j - 1] ? dpr[i][j] + 1 : max(dpr[i - 1][j], dpr[i][j - 1]);
            }
        }
        //dpr[i][j] == lcs(s1[i to end], s2[j to end])
        
        int ans = 0;
        //Insert before position i of s1 and mark the inserted character.
        vector<array<bool, 26>> Insert(N1 + 1);
        for (int i = 0; i <= N1; ++i) {
            for (int j = 0; j < N2; ++j) {
                if (dpl[i][j] + dpr[i][j + 1] == dpl[N1][N2])
                    Insert[i][s2[j] - 'a'] = 1;
            }
        }
        for (auto &v : Insert) {
            ans += accumulate(v.begin(), v.end(), 0);
        }
        return ans;
    }
};
