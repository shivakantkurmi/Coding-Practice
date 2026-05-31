class Solution {
  public:
    bool isSumOfConsecutive(int n) {
        // code here
        return (n & (n-1)) != 0;//as long as number is not the power of 2 they can be repesented by consicutive sum 
    }
};
