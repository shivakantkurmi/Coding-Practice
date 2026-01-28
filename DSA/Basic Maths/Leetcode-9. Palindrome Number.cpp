class Solution {
  public:
    bool isPalindrome(int n) {
        if(n<0)return false;
        int rev=0,temp=n;
        while(temp){
            if(rev>INT_MAX/10 ) return 0;
            rev=rev*10+temp%10;
            temp/=10;
        }
        return rev==n;
    }
};

//constraints : -231 <= x <= 231 - 1
