Link : https://www.geeksforgeeks.org/problems/max-sum-in-the-configuration/1

class Solution {
public:
    int maxSum(vector<int>& arr) {
        int n = arr.size();

        int totalSum = 0; 
        int currValue = 0; 

        for (int i = 0; i < n; i++) {
            totalSum += arr[i];
            currValue += i * arr[i];
        }

        int ans = currValue;  

        for (int i = n - 2; i >= 0; i--) {
            currValue = currValue - (arr[i + 1] * (n - 1)) + (totalSum - arr[i + 1]);
            ans = max(ans, currValue);
        }

        return ans;
    }
};
