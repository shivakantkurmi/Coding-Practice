class Solution {
public:
    int countStrings(int n) {
        long long zero = 1;
        long long one = 1;
        for(int i = 2; i <= n; i++) {
            long long newZero = zero + one;
            long long newOne = zero;
            zero = newZero;
            one = newOne;
        }
        return zero + one;
    }
};
