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


// 2nd way
class Solution {
    public:
     int reverseBits(int n){
        int num=0;
        for(int i=0;i<32;i++){
            if(n%2==0)num=(num<<1);
            else num= (num<<1)|1;
            n/=2;
        }
        return num;
     }
};
