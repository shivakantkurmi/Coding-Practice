class Solution {
public:
    char findKthBit(int n, int k) {
        if (n == 1) return '0';//base if n=1 the only bit is 0
        int len = (1 << n) - 1;//length of sn is 2^n -1
        int mid = len / 2 + 1; //so mid is (len/2)+1
        if (k == mid) return '1';//mid bit is always 1
        if (k < mid) return findKthBit(n - 1, k); //left half so search in Sn-1
        return findKthBit(n - 1, len - k + 1) == '0' ? '1' : '0';//2nd half reversed and inverted ie if 1 then return 0 and vice versa
    }
};
