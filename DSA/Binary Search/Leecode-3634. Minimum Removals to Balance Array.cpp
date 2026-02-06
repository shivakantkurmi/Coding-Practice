class Solution {
public:
    int slightmin(vector<int>&nums,int k,int i){
        long long key=nums[i]*(long long)k;
        int left=0,right=nums.size()-1;
        int ans=right;
        while(left<=right){
            int mid=left+(right-left)/2;
            // if(nums[mid]=key)return mid;
            if(nums[mid]<=key){
                ans=mid;
                left=mid+1;
            }
            else 
                right=mid-1;
        }
        return ans;
    }
    int minRemoval(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        long long km=nums[0]*(long long)k;
        if(km>=nums[n-1]||n==1) return 0;
        int remove=INT_MAX;
        for(int i=0;i<n;i++){
            int j=slightmin(nums,k,i);
            remove=min(remove,n - (j - i + 1));
        }
        return remove;
    }
};
