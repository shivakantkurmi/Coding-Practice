/*
For n= 3,
pattern:3 3 3 2 2 2 1 1 1
        3 3 2 2 1 1 
        3 2 1
*/


class Solution {
  public:
    vector<int> printPat(int n) {
        // write code here
        vector<int>ans;
        for(int i=n;i>0;i--){
            int x=n;
            int y=0;
            for(int j=1;j<=n*i;j++){
                if(y==i){
                    x--;
                    y=0;
                }
                y++;
                ans.push_back(x);
            }
            ans.push_back(-1);
        }
        return ans;
    }
};
