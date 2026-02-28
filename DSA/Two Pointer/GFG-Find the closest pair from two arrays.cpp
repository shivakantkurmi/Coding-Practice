class Solution {
public:
    vector<int> findClosestPair(vector<int> &arr1,
                                vector<int> &arr2,
                                int x) {

        int n = arr1.size();
        int m = arr2.size();

        int i = 0;
        int j = m - 1;

        int diff = INT_MAX;
        vector<int> ans;

        while(i < n && j >= 0) {

            int sum = arr1[i] + arr2[j];
            int t = abs(sum - x);

            if(t < diff) {
                diff = t;
                ans = {arr1[i], arr2[j]};
            }

            if(sum > x)
                j--;   // reduce sum
            else
                i++;   // increase sum
        }

        return ans;
    }
};
