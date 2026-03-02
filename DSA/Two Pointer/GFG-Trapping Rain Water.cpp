//link : https://www.geeksforgeeks.org/problems/trapping-rain-water-1587115621/1

class Solution {
  public:
    int maxWater(vector<int> &arr) {
        // code here
        int n=arr.size();
        int leftMax=arr[0],rightMax=arr[n-1];
        int i=0,j=n-1;
        int ans=0;
        // water[i]=min(leftMax,rightMax)-height[i]; 
        while(i<=j){
            if(leftMax<=rightMax){
                leftMax=max(leftMax,arr[i]);
                ans+=(leftMax-arr[i]);
                i++;
            }
            else{
                rightMax=max(rightMax,arr[j]);
                ans+=(rightMax-arr[j]);
                j--;
            }
        }
        return ans;
        
    }
};
