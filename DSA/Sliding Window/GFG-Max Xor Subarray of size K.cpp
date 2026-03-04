class Solution {
  public:
    int maxSubarrayXOR(vector<int>& arr, int k) {
        // code here
        int ans=0;
        for(int i=0;i<k;i++)ans^=arr[i];
        int temp=ans;
        for(int i=k;i<arr.size();i++){
            temp^=arr[i-k];
            temp^=arr[i];
            if(ans<temp)ans=temp;
        }
        return ans;
    }
};
