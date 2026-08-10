class Solution {
  public:
    int days=0;
    int solve(int day,bool prv,vector<int>& h, vector<int>& l,vector<vector<int>> &dp){
        if(day>=days)
            return 0;
        int p=prv==true?1:0;
        if(dp[day][p]!=-1)
            return dp[day][p];
        
        int low=l[day]+solve(day+1,true,h,l,dp);
        int high=0;
        if(!prv)
            high=h[day]+solve(day+1,true,h,l,dp);
        int noEff=solve(day+1,false,h,l,dp);
        
        return dp[day][p]=max(max(low,high),noEff);
    }
    int maxTask(vector<int>& h, vector<int>& l) {
        days=h.size();
        vector<vector<int>> dp(l.size(),vector<int>(2,-1));
        return solve(0,false,h,l,dp);
    }
};
