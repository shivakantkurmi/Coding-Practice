class Solution {
  public:
    string chooseSwap(string &s) {
        int n = s.size();

        vector<int> first(26, -1);
        for (int i = 0; i < n; i++) {
            if (first[s[i] - 'a'] == -1)
                first[s[i] - 'a'] = i;
        }

        for (int i = 0; i < n; i++) {
            for (char ch = 'a'; ch < s[i]; ch++) {
                if (first[ch - 'a'] > i) {
                    char a = s[i];
                    char b = ch;

                    for (char &c : s) {
                        if (c == a)
                            c = b;
                        else if (c == b)
                            c = a;
                    }
                    return s;
                }
            }
        }

        return s;
    }
};
