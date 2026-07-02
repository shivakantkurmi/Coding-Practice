class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        // next_permutation(nums.begin(),nums.end());  //using built in 

        int pivot=-1,n=nums.size();
        //step1: find pivot
        for(int i=n-2;i>=0;i--){
            if(nums[i]<nums[i+1]){
                pivot=i;
                break;
            }
        }
        if(pivot==-1){
            //no pivot means entire array is descending so return smllest arrangment ie reverse the array
            reverse(nums.begin(),nums.end());
            return;
        }
        //step 2: find reightmost elemnt which is greater than pivot element and swap both
        for(int i=n-1;i>pivot;i--){
            if(nums[i]>nums[pivot]) {
                swap(nums[i],nums[pivot]);
                break;
            }
        }

        //step 3: make minimum number after pivot means pivot+1 to n-1 which is simply reverse of it
        reverse(nums.begin()+pivot+1,nums.end());
    }
};
