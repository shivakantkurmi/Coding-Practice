// Link : http://geeksforgeeks.org/problems/maximize-number-of-1s0905/1

class Solution {
  public:
    int maxOnes(vector<int>& arr, int k) {
        // code here
        int left=0,zero=0;
        int i=0,ans=-1;
        int n=arr.size();
        while(i<n){
            if(arr[i]==0)zero++;
            while(zero>k){
                if(arr[left]==0)zero--;
                left++;
            }
            ans=max(ans,i-left+1);
            i++;
        }
        return ans;
    }
};
