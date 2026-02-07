class Solution {
public:
    bool checkPerfectNumber(int num) {
        if(num==1) return false;
        int n=1;
        for(int i=2;i*i<=num;i++){
            if(num%i==0){
                n+=i;
                if(i!=num/i)n+=(num/i);
            }
        }
        return num==n;
    }
};
