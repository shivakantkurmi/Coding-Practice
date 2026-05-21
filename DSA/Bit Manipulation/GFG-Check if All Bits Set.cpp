// class Solution {
//   public:
//     bool isBitSet(int n) {
//         // code here
//         if(n==0) return false;
//         while(n){
//             if(n%2==0) return false;
//             n/=2;
//         }
//         return true;
//     }
// };


class Solution {
  public:
    bool isBitSet(int n) {
        
        if (n == 0)
            return false;

        return (n & (n + 1)) == 0;
    }
};
