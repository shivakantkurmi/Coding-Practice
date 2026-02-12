class Solution {
  public:
    int findSubarray(vector<int> &arr) {
        // code here.
        int n=arr.size();
        int cnt = 0,preSum = 0;

        unordered_map<int,int>mp;

        for(int i = 0; i < n; i++){ 

            preSum += arr[i];

            mp[preSum]++;

            if(preSum == 0)  cnt++;

        }

        for(auto &i : mp)   cnt += ((i.second)*(i.second-1))/2;

        return cnt;
    }
};



//
class Solution {
  public:
    int findSubarray(vector<int> &arr) {
        // code here.
        unordered_map<int,int> mp;
        int sum = 0, count = 0;
    
        mp[0] = 1; // important
    
        for(int x : arr){
            sum += x;
            if(mp.count(sum))
                count += mp[sum];
            mp[sum]++;
        }
        return count;
    }
};
