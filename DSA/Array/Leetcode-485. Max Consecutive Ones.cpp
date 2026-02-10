class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int maxOne=0;
        int temp=0;
        for(int i:nums){
            if(i==0){
                temp=0;
            }
            else temp++;
            maxOne=max(maxOne,temp);
        }
        return maxOne;
    }
};
