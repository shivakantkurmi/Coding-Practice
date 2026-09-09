class Solution {
  public:
    vector<int> gfSeries(int n) {
        // code here
        int prev2=0,prev1=1;
        
        vector<int>arr={0,1};
        for(int i=3;i<=n;i++){
            int x=prev2*prev2 - prev1;
            prev2=prev1;
            prev1=x;
            arr.push_back(x);
        }
        return arr;
    }
};
