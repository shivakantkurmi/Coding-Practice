class Solution {
    bool isPalindrom(int n){
        int x=n;
        int rev=0;
        while(x){
            rev=rev*10+(x%10);
            x/=10;
        }
        return rev==n;
    }
  public:
    bool isPalinArray(vector<int> &arr) {
        // code here
        for(int i:arr){
            if(!isPalindrom(i))return false;
        }
        return true;
        
    }
};
