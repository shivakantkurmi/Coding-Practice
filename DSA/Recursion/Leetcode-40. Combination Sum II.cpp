class Solution {
    vector<vector<int>> ans;
public:
    void targetSum(int idx, int sum, int target, vector<int> &arr, vector<int> &t){
        if(sum == target){
            ans.push_back(t);
            return;
        }
        if(sum > target) return;
        for(int i = idx; i < arr.size(); i++){
            if(i > idx && arr[i] == arr[i-1])
                continue;
            t.push_back(arr[i]);
            targetSum(i + 1, sum + arr[i], target, arr, t);
            t.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<int> t;
        targetSum(0, 0, target, candidates, t);
        return ans;
    }
};
