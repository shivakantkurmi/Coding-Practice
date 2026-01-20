// class Solution {
// public:
//     vector<int> minBitwiseArray(vector<int>& nums) {
//         int n = nums.size();
//         vector<int> ans(n, -1);
//         for (int i = 0; i < n; i++) {
//             for (int j = 0; j <= nums[i]; j++) {
//                 if ((j | (j + 1)) == nums[i]) {
//                     ans[i] = j;
//                     break;
//                 }
//             }
//         }
//         return ans;
//     }
// };

class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n);
        for(int i = 0; i < n; ++i) {
            if(nums[i] == 2) {
                ans[i] = -1;
            }
            else {
                for(int j = 1; j < 20; ++j) {
                    if(nums[i] & (1 << j)) {
                    }
                    else {
                        int mask = 1 << (j - 1);
                        mask = ~mask;
                        nums[i] = nums[i] & mask;
                        break;
                    }
                }

                ans[i] = nums[i];
            }
        }

        return ans;
    }
};
