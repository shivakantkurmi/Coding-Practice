class Solution {
public:
    int totalNumbers(vector<int>& digits) {
        vector<int> cnt(10, 0);
        for (int d : digits)
            cnt[d]++;
        int ans = 0;
        for (int last = 0; last <= 8; last += 2) {
            if (cnt[last] == 0)
                continue;
            cnt[last]--;
            for (int first = 1; first <= 9; first++) {
                if (cnt[first] == 0)
                    continue;
                cnt[first]--;
                for (int middle = 0; middle <= 9; middle++) {
                    if (cnt[middle] > 0)
                        ans++;
                }

                cnt[first]++;
            }

            cnt[last]++;
        }

        return ans;
    }
};
