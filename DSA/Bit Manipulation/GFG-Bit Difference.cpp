class Solution {
public:
    int countBitsFlip(int a, int b) {
        int x = a ^ b;
        int cnt = 0; //now just count set bits as 0^1=1^0=1

        while (x) {
            x &= (x - 1);
            cnt++;
        }

        return cnt;
    }

};


/*
class Solution {
public:
    int countBitsFlip(int a, int b) {
        return __builtin_popcount(a ^ b);
    }
};
*/
