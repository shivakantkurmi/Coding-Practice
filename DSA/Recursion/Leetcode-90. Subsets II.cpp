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
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int> t;
        sort(nums.begin(),nums.end());
        combinations(0,nums,t);
        return ans;
    }
};

//bitmasking and iterations
// class Solution {
// public:
//     vector<vector<int>> subsetsWithDup(vector<int>& nums) {
//         set<vector<int>> ans;
//         sort(nums.begin(),nums.end());
//         int n =nums.size();
//         for(int mask=0;mask<(1<<n);mask++){
//             vector<int> t;
//             for(int i=0;i<n;i++){
//                 if(mask&(1<<i))t.push_back(nums[i]);
//             }
//             ans.insert(t);
//         }
//         vector<vector<int>> result(ans.begin(),ans.end());
//         return result;
//     }
// };
