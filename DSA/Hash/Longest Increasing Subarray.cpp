class Solution {
public:
    vector<int> LongestIncreaingSubarray(vector<int>& arr) {
        int n = arr.size();
        if(n == 0) return {};

        int start = 0, maxStart = 0;
        int len = 1, maxLen = 1;

        for(int i = 1; i < n; i++) {
            if(arr[i] > arr[i-1]) {
                len++;
            } else {
                if(len > maxLen) {
                    maxLen = len;
                    maxStart = start;
                }
                start = i;
                len = 1;
            }
        }

        // final check
        if(len > maxLen) {
            maxLen = len;
            maxStart = start;
        }

        return vector<int>(arr.begin()+maxStart,
                           arr.begin()+maxStart+maxLen);
    }
};
