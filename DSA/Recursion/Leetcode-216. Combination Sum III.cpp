class Solution {
    vector<vector<int>> ans;
    void targetSum(int idx, int target, int k, vector<int>&t){
        if(t.size()==k && target==0){
            ans.push_back(t);
            return;
        }
        if(target<0 || idx>9) return;
        t.push_back(idx);
        targetSum(idx+1, target-idx, k, t);
        t.pop_back();
        targetSum(idx+1, target, k, t);

    }
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> t;
        targetSum(1,n,k,t);
        return ans;
    }
};
