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



//2nd way
class Solution {
    vector<int> subSum;
    void solve(int idx, vector<int>&arr, int sum, int n){
        if(idx==n){
            subSum.push_back(sum);
            return;
        }
        solve(idx+1,arr,sum+arr[idx],n);
        solve(idx+1,arr,sum,n);
    }
  public:
    vector<int> subsetSums(vector<int>& arr) {
        // code here
        solve(0,arr,0,arr.size());
        return subSum;
        
    }
};
