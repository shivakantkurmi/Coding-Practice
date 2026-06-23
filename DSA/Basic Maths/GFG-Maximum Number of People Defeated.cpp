class Solution {
  public:
   int maxPeopleDefeated(int p) {
        // Code Here
        int cnt=0;
        int sum=0;
        int i=1;
        while(p>=(i*i))
        {
           cnt++;
           p -= i*i;
           i++;
        }
        return cnt;
        
    }
};
