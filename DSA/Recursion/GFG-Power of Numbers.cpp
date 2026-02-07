class Solution {
  public:
    int reverse(int n , int reversed){
        if(n==0) return reversed;
        return reverse(n/10,reversed*10+n%10);
    }
    int power(int num,int x){
        if(x==0) return 1;
        if (x==1)return num;
        if(x%2==0){
            int half=power(num,x/2);
            return half*half;
        }
        else return num*power(num,x-1);
    }
    int reverseExponentiation(int n) {
        int p=reverse(n,0);
        return power(n,p);
        
    }
};
