class Solution {
    vector<vector<int>> ans;
    void targetSum(int idx, int n,int target , int sum, vector<int> &arr, vector<int> &t){
        if(sum==target){
            ans.push_back(t);
            return;
        }
        if(sum>target) return ;
        if(idx>=n) return ;
        t.push_back(arr[idx]);
        targetSum(idx,n,target,sum+arr[idx],arr,t);//as allow multiple times same number
        t.pop_back();
        targetSum(idx+1,n,target,sum,arr,t);
    }
  public:
    vector<vector<int>> targetSumComb(vector<int> &arr, int target) {
        vector<int> t;
        targetSum(0,arr.size(),target,0,arr,t);
        return ans;
        
    }
};
