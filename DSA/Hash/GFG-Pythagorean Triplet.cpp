class Solution {
  public:
    bool pythagoreanTriplet(vector<int>& arr) {
        // code here
        unordered_map<int,int> mp;
        int n=arr.size();
        for(int i:arr)mp[i*i]++;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int x=arr[i]*arr[i]+arr[j]*arr[j];
                if(mp.find(x)!=mp.end()) return true;
            }
        }
        return false;
    }
};
