// class Solution {
// public:
//     int arrayPairSum(vector<int>& nums) {
//         sort(nums.begin(), nums.end());
//         int sum = 0;
//         for(int i = 0; i < nums.size(); i += 2){
//             sum += nums[i];
//         }
//         return sum;
//     }
// };


//using counting sort (o(n))
class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
        vector<int> count(20001, 0);

        for(int x : nums)
            count[x + 10000]++; // to make freq of negative integrs positive -10^4=-10000 so adding 10000 will make it 0

        int sum = 0;
        bool take = true;

        for(int i = 0; i < 20001; i++){
            while(count[i]--){
                if(take) sum += i - 10000;
                take = !take; //to skip one and take one in order so fist element will pick ( default minimum as sorted and next will not be piked and so one and so forth)
            }
        }

        return sum;
    }
};

