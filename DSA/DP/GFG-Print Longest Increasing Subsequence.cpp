class Solution {
public:
    vector<int> getLIS(vector<int>& arr) {
        int n = arr.size();
        if(n == 0) return {};

        vector<int> dp(n, 1);
        vector<int> parent(n, -1);

        int maxLen = 1;
        int lastIdx = 0;

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < i; j++) {
                if(arr[j] < arr[i] && dp[j] + 1 > dp[i]) {
                    dp[i] = dp[j] + 1;
                    parent[i] = j;
                }
            }

            if(dp[i] > maxLen) {
                maxLen = dp[i];
                lastIdx = i;
            }
        }

        // Reconstruct LIS
        vector<int> lis;
        while(lastIdx != -1) {
            lis.push_back(arr[lastIdx]);
            lastIdx = parent[lastIdx];
        }

        reverse(lis.begin(), lis.end());
        return lis;
    }
};
