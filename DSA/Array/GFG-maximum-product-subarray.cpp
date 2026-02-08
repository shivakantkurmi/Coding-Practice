// Link : https://www.geeksforgeeks.org/problems/maximum-product-subarray3604/1


class Solution {
  public:
    int maxProduct(vector<int> &arr) {
        // code here
        int maxProd=arr[0];
        int minProd=arr[0];
        int ans=arr[0];
        for(int i=1;i<arr.size();i++){
            int temp=maxProd;
            maxProd=max({arr[i],maxProd*arr[i],minProd*arr[i]});
            minProd=min({arr[i],temp*arr[i],minProd*arr[i]});
            ans=max(ans,maxProd);
        }
        return ans;
    }
};
