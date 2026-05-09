// class Solution {
// public:
//     vector<vector<int>> subsets(vector<int>& nums) {
//         int n=nums.size();
//         vector<vector<int>> ans;
//         for(int mask=0;mask<(1<<n);mask++){
//             vector<int> t;
//             for(int i=0;i<n;i++){
//                 if(mask&(1<<i)) t.push_back(nums[i]);
//             }
//             ans.push_back(t);
//         }
//         return ans;
//     }
// };

// //using Recursion
// class Solution {
//     vector<vector<int>> ans;
//     void combinations(int idx, vector<int> &arr, vector<int> &t){
//         if(idx==arr.size()){
//             ans.push_back(t);
//             return;
//         }
//         t.push_back(arr[idx]);
//         combinations(idx+1,arr,t);
//         t.pop_back();
//         combinations(idx+1,arr,t);
//     }
// public:
//     vector<vector<int>> subsets(vector<int>& nums) {
//         vector<int> t;
//         combinations(0,nums,t);
//         return ans;
//     }
// };

//3rd Way
class Solution {
    vector<vector<int>> ans;
    void combinations(int idx, vector<int> &arr, vector<int> &t){
        ans.push_back(t); //we are calling this as any idx reach this when the for loop breaks completly which already runs from 0 to n-1 and breaks at n
        for(int i=idx; i<arr.size();i++){
            t.push_back(arr[i]);
            combinations(i+1,arr,t);
            t.pop_back();
        }
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> t;
        combinations(0,nums,t);
        return ans;
    }
};
