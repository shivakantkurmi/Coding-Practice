//Link : https://www.geeksforgeeks.org/problems/find-all-pairs-whose-sum-is-x5808/1?page=2&category=Hash&sortBy=submissions


class Solution {
  public:
    // Function to find all pairs with given sum.
    vector<pair<int, int>> allPairs(int target, vector<int> &arr1, vector<int> &arr2) {
        // Code here
        sort(arr1.begin(),arr1.end());
        unordered_map<int,int>mp;
        for(int &i:arr2)mp[i]++;
        vector<pair<int,int>>res;
        
        for(int i:arr1){
            int k=target-i;
            if(mp.find(k)!=mp.end()){
                int x=mp[k];
                while(x){
                    res.push_back({i,k});
                    x--;
                }
            }
        }
        return res;
        
    }
};
