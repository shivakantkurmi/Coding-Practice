class Solution {
    int bit_length(int n){
        if(n<=1)return 1;
        return 1+bit_length(n/2);
    }
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int n=nums.size();
        if (n < 3)
            return  n;
        else
            return  pow(2,(bit_length(n)));
    }   
};
