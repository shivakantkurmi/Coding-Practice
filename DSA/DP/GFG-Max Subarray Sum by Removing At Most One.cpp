class Solution {
  public:
    int maxSumSubarray(vector<int>& arr) {
        int keep = arr[0];
        int remove = 0;
        int ans = arr[0];
        for (int i = 1; i < arr.size(); i++) {
            remove = max(keep, remove + arr[i]);
            keep = max(arr[i], keep + arr[i]);
            ans = max(ans, max(keep, remove));
        }
        return ans;
    }
};
