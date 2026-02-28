class Solution {
public:
    int concatenatedBinary(int n) {

        const int MOD = 1e9 + 7;
        long long ans = 0;
        int len = 0;

        for(int x = 1; x <= n; x++) {
            if((x & (x - 1)) == 0)
                len++;

            ans = ((ans << len) | x) % MOD;
        }

        return ans;
    }
};
