class Solution {
    vector<int> subSum;
    void solve(int idx, vector<int>&arr, int sum, int n){
        subSum.push_back(sum);
        for(int i=idx;i<n;i++){
            sum+=arr[i];
            solve(i+1,arr,sum,n);
            sum-=arr[i];
        }
        return;
    }
  public:
    vector<int> subsetSums(vector<int>& arr) {
        // code here
        solve(0,arr,0,arr.size());
        return subSum;
        
    }
};
