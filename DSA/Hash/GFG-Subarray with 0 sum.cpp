class Solution {
  public:
    // Complete this function
    // Function to check whether there is a subarray present with 0-sum or not.
    bool subArrayExists(vector<int>& arr) {
        // Your code here
        unordered_map<int,int> mp;
        int tsum=0;
        for(int i:arr){
            tsum+=i;
            if(tsum==0 || mp.find(tsum)!=mp.end()) return true;
            mp[tsum]++;
        }
        return false;
    }
};


//Using set 

class Solution {
  public:
    // Complete this function
    // Function to check whether there is a subarray present with 0-sum or not.
    bool subArrayExists(vector<int>& arr) {
        // Your code here
        unordered_set<int> ans;
        int sum=0;
        int n=arr.size();
        for(int i=0;i<n;i++){
            sum+=arr[i];
            if(sum==0 || ans.count(sum)>0){
                return true;
            }
            ans.insert(sum);
        }
        return false;
    }
};
