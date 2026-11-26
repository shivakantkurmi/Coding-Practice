class Solution {
  public:

    bool isVowel(char& ch) {

        return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';
    }

    vector<int> countVowels(string &s, vector<vector<int>> &queries) {
        // code here

        int n = s.size();
        vector<int> prefix(n, 0);

        prefix[0] = isVowel(s[0]);

        for (int i = 1; i < n; i++) {

            int curr = isVowel(s[i]);
            prefix[i] = curr + prefix[i-1];
        }

        vector<int> ans;

        for (auto& q : queries) {

            int l = q[0];
            int r = q[1];

            int total = prefix[r] - (l > 0 ? prefix[l-1] : 0);

            ans.push_back(total);
        }

        return ans;
    }
};
