class Solution {
    vector<vector<int>> ans;
    void combinations(int idx, vector<int> &arr, vector<int> &t){
        ans.push_back(t);
        for(int i=idx;i<arr.size();i++){
            if(i>idx && arr[i]==arr[i-1]) continue;
            t.push_back(arr[i]);
            combinations(i+1,arr,t);
            t.pop_back();
        }
    }
  public:
    vector<vector<int>> findSubsets(vector<int>& arr) {
        // code here
        vector<int> t;
        sort(arr.begin(),arr.end());
        combinations(0,arr,t);
        return ans;
        
    }
};

