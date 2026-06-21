class Solution {
  public:
    int maxArea(vector<int> &height) {
        // code here
        int n=height.size();
        int left=0,right=n-1;
        int ans=0;
        while(left<right){
            int diff=right-left-1;
            int temp=diff*min(height[left],height[right]);
            ans=max(temp,ans);
            if(height[left]<height[right])left++;
            else right--;
        }
        return ans;
        
    }
};
