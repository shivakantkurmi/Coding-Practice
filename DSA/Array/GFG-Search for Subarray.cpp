class Solution {
    void computeLPSArray(vector<int>& p, vector<int>& lps) {
        int n = p.size();
        lps.resize(n);

        int len = 0;
        lps[0] = 0;

        int i = 1;

        while (i < n) {
            if (p[i] == p[len]) {
                len++;
                lps[i] = len;
                i++;
            } 
            else {
                if (len != 0) {
                    len = lps[len - 1];
                } 
                else {
                    lps[i] = 0;
                    i++;
                }
            }
        }
    }

public:
    vector<int> search(vector<int> &a, vector<int> &b) {
        int n = a.size();
        int m = b.size();

        vector<int> lps;
        computeLPSArray(b, lps);

        vector<int> ans;

        int i = 0, j = 0;

        while (i < n) {
            if (a[i] == b[j]) {
                i++;
                j++;
            }

            if (j == m) {
                ans.push_back(i - j);
                j = lps[j - 1];
            }
            else if (i < n && a[i] != b[j]) {
                if (j != 0)
                    j = lps[j - 1];
                else
                    i++;
            }
        }

        return ans;
    }
};
