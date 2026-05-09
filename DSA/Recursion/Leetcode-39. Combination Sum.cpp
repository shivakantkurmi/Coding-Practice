class Solution {
    vector<vector<int>> ans;
public:
    void targetSum(int idx, int n,int target , int sum, vector<int> &arr, vector<int> &t){
        if(sum==target){
            ans.push_back(t);
            return;
        }
        if(sum>target) return ;
        if(idx>=n) return ;
        t.push_back(arr[idx]);
        // targetSum(idx+1,n,target,sum+arr[idx],arr,t);//if only allow once to take element
        targetSum(idx,n,target,sum+arr[idx],arr,t);//as allow multiple times same number
        t.pop_back();
        targetSum(idx+1,n,target,sum,arr,t);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> t;
        targetSum(0,candidates.size(),target,0,candidates,t);
        return ans;
    }
};
