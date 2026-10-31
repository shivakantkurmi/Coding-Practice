class Solution {
  public:
    int maxPackages(vector<int>& arr, int totalTime) {
        // code here
        int ans=INT_MIN;
        int sum=0;
        for(int i=0;i<arr.size();i++){
            sum+=arr[i];
            if(i>=totalTime){
                sum-=arr[i-totalTime];
            }
            ans=max(ans,sum);
        }
        return ans;
    }
};
