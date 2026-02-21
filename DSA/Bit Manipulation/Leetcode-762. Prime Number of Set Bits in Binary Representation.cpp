class Solution {
    int prime[33]={0,0,1,1,0,1,0,1,0,0, 0,1,0,1,0,0,0,1,0,1, 0,0,0,1,0,0,0,0,0,1, 0,1,0};
public:
    int countPrimeSetBits(int left, int right) {
        int ans = 0;
        for(int i=left; i<=right; i++)
        {
            if (prime[__builtin_popcount(i)]) ans++;

        }
        return ans;
    }
};
