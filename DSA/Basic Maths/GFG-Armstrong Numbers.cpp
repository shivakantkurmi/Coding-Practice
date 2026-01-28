// User function Template for C++
class Solution {
  private:
    int pow(int base,int power){
      int num=1;
      for(int i=0;i<power;i++)num*=base;
      return num;
  }
  public:
    bool armstrongNumber(int n) {
        // code here constarints : 100 ≤ n <1000 
        //contains says only 3 digit number so  
        int digits=3;
        int x=n,n2=0;
        while(x){
            n2+=pow((x%10),digits);
            x/=10;
        }
        return n==n2;
        
    }
};
