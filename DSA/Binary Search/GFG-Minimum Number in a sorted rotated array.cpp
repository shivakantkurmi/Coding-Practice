class Solution {
  public:
    // Function to find the minimum element in sorted and rotated array.
    int minNumber(int arr[], int low, int high) {
        // Your code here
        int ans=INT_MAX;
        while(low<=high){
            int mid=low+(high-low)/2;
          //left half is sorted
            if(arr[mid]>=arr[low]){
                ans=min(ans,arr[low]);
                low=mid+1;
            }
              //right half is sorted
            else{
                ans=min(arr[mid],ans);
                high=mid-1;
            }
        }
        return ans;
    }
};
