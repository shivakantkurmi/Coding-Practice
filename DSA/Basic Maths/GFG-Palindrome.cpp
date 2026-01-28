class Solution {
  public:
    bool isPalindrome(int n) {
        // code here.
        int rev=0,temp=n;
        while(temp){
            rev=rev*10+temp%10;
            temp/=10;
        }
        return rev==n;
    }
};
