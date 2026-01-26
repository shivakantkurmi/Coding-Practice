class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        int minDiff=INT_MAX;
        sort(arr.begin(),arr.end());
        int n=arr.size();
        for(int i=0;i<n-1;i++){
            if(arr[i+1]-arr[i]<minDiff)minDiff=arr[i+1]-arr[i];
        }
        vector<vector<int>> ans;
        for(int i=0;i<n-1;i++){
            if(arr[i+1]-arr[i]==minDiff)ans.push_back({arr[i],arr[i+1]});
        }
        return ans;
    }
};
