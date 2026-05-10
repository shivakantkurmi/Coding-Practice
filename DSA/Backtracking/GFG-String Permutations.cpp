class Solution {
    vector<string> ans;

    void solve(int idx, string &S) {
        if(idx == S.size()) {
            ans.push_back(S);
            return;
        }

        for(int i = idx; i < S.size(); i++) {
            swap(S[idx], S[i]);
            solve(idx + 1, S);
            swap(S[idx], S[i]);
        }
    }

public:
    vector<string> permutation(string S) {
        sort(S.begin(), S.end());
        solve(0, S);
        sort(ans.begin(), ans.end());
        return ans;
    }
};
