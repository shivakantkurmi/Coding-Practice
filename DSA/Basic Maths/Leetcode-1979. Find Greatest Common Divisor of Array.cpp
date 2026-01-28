class Solution {
private:
    int gcd(int a,int b){
        if(b==0) return a;
        return gcd(b,a%b);
    }
public:
    int findGCD(vector<int>& nums) {
        int min=INT_MAX,max=INT_MIN;
        for(int i:nums){
            if(i>max)max=i;
            if(i<min)min=i;
        }
        return gcd(min,max);
    }
};
