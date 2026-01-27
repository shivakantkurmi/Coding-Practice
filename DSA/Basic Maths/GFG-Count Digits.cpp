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
//TC-O(log10(n)) sc-O(1)

//2nd Way :

class Solution {
  public:
    int countDigits(int n) {
        // code here
        int cnt=(int)(log10(n)+1);
        return cnt;
    }
};
//TC-O(1) sc-O(1)
