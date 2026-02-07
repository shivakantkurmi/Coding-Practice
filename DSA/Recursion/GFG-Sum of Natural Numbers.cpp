class Solution {
  public:
    int findSum(int n) {
        // code here
        // return n*(n+1)/2;
        // By using Recursion 
        if(n==1) return 1;
        return n+findSum(n-1);
    }
};
