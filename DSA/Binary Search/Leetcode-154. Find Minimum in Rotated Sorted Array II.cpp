class Solution {
    int solve(vector<int> &arr){
        int low=0,high=arr.size()-1;
        int ans=INT_MAX;
        while(low<=high){
            while(low<high && arr[low]==arr[low+1]) low++;
            while(low<high && arr[high]==arr[high-1]) high--;
            int mid=low+(high-low)/2;
            if(arr[low]<arr[high]){
                ans=min(ans,arr[low]);
                break;
            }
            if(arr[low]<=arr[mid]){
                ans=min(arr[low],ans);
                low=mid+1;
            }

            else{
                ans=min(arr[mid],ans);
                high=mid-1;
            }
        }
        return ans;
    }
public:
    int findMin(vector<int>& nums) {
        return solve(nums);
    }
};
