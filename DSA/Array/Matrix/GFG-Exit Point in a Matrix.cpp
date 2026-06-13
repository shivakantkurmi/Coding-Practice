class Solution {
  public:
    vector<int> exitPoint(vector<vector<int>>& mat) {
        // code here
        int i=0,j=0;
        int di=0,dj=1;
        int n=mat.size(),m=mat[0].size();
        while(true){
            if(mat[i][j]==1){
                if(di==1)dj=-1,di=0;
                else if(di==-1)dj=1,di=0;
                else if(dj==1)di=1,dj=0;
                else di=-1,dj=0;
                mat[i][j]=0;
            }
            i+=di,j+=dj;
            if(i<0 || j<0 ||i>=n ||j>=m) return {i-di,j-dj};
        }
        return {};
    }
};
