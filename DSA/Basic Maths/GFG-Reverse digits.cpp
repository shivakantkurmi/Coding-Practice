class Solution {
  public:
    int reverseDigits(int n) {
        // Code here
        int rev=0;
        while(n){
            rev=rev*10+n%10;
            n/=10;
        }
        return rev;
    }
};
