//DFS Solution
class Solution {
    bool solve(vector<int>& arr, int i, vector<int>& vis){
        if(i < 0 || i >= arr.size() || vis[i]) return false;
        if(arr[i] == 0) return true;
        vis[i] = 1;
        return solve(arr, i + arr[i], vis) ||
               solve(arr, i - arr[i], vis);
    }

public:
    bool canReach(vector<int>& arr, int start) {
        vector<int> vis(arr.size(), 0);
        return solve(arr, start, vis);
    }
};
