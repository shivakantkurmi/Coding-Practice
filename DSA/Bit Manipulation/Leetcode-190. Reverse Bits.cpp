class Solution {
public:
    int reverseBits(int n) {
        int num=0;
        for(int i=31;i>=0;i--){
            int bit=n&(2147483648>>i);
            num=num<<1;
            if(bit)num=num+1;
        }
        return num;
    }
};
