class Solution {
  public:
    int countDigits(int n) {
        // code here
        int count=0;
        while(n){
            count++;
            n/=10;
        }
        return count;
    }
};
