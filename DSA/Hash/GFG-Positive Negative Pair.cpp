// User function template for C++

class Solution {
  public:
    // Function to return list containing all the pairs having both
    // negative and positive values of a number in the array.
    vector<int> findPairs(int arr[], int n) {
        // code here
        unordered_map<int,int> mp;
        vector<int>ans;
        for(int x=0;x<n;x++){
            int i=arr[x];
            if(mp.find(-i)!=mp.end()){
                ans.push_back(-(abs(i)));
                ans.push_back(abs(i));
            }
            mp[i]++;
        }
        return ans;
    }
};
