class Solution {
private:
    vector<vector<int>> ans;

public:
    void solve(int idx, vector<int>& nums, vector<int>& arr){
        if(idx == nums.size()){
            ans.push_back(arr);
            return;
        }

        arr.push_back(nums[idx]);
        solve(idx + 1, nums, arr);

        arr.pop_back();
        solve(idx + 1, nums, arr);
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> arr;
        solve(0, nums, arr);
        return ans;
    }
};
