class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        int n=nums.size();
        vector<int> ans(n,-1);
        for(int i=0;i<n;i++){
            if(nums[i]==2){
                ans[i]=-1;
            }
            else{
                for(int j=1;j<32;j++){
                    if(nums[i] & (1<<j)) continue;
                    else {
                        int mask=1<<(j-1);
                        mask=~mask;
                        nums[i]=nums[i]&mask;
                        break;
                    }
                }
                ans[i]=nums[i];
            }
            
        }
        return ans;
    }
};



//2ND WAY TO SOLVE WITH SAME APPROACH 
class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        // Adding 1 in any number has a property that in binary representation all the numbers on the left side of first '0' remains same and all the '1s' on the right side of the first '0' become 0;
        // next is that the first '0' become '1'
        // using this property we can find min optimally...

        vector<int> ans;

        for(auto& i: nums){
            if(i==2){
                ans.push_back(-1);
            }
            else{
                int val = ~i;
                int temp = val&(-val); // this will return a number which has set bit only at the position where our initial number has rightmost bit as '0';
                temp>>=1;
                int out = i&(~temp); // I want to make the closest '1' of the rightmost '0' as '0';
                ans.push_back(out);
            }
        }
        return ans;

    }
};
