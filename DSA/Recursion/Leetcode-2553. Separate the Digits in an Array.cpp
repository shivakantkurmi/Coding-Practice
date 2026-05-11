class Solution {
    void solve(vector<int> &ans, int n){
        if(n<10){
            ans.push_back(n);
            return;
        }
        solve(ans,n/10);
        ans.push_back(n%10);
    }
public:
    vector<int> separateDigits(vector<int>& nums) {
        vector<int> ans;
        for(int i:nums){
            solve(ans,i);
        }
        return ans;
    }
};
