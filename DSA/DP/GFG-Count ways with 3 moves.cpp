
class Solution {
  public:
    int countWays(int n) {
        // your code here
        if(n==1||n==2) return n;
        if(n==3) return 4;
        int first=1,second=2,third=4;
        int ans=0;
        for(int i=4;i<=n;i++){
            ans=first+second+third;
            first=second;
            second=third;
            third=ans;
        }
        return ans;
    }
};
