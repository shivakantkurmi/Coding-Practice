class Solution {
  public:
    bool solve(int ind, int sum, vector<int> &arr,int k){
        if(sum>k) return false;
        if(sum==k) return true;
        if(ind>=arr.size()) return false;
        if(solve(ind+1,sum+arr[ind],arr,k)||(solve(ind+1,sum,arr,k))) return true;
        return false;
    }
    bool checkSubsequenceSum(vector<int>& arr, int k) {
        // Code here
        return solve(0,0,arr,k);
        
    }
};
