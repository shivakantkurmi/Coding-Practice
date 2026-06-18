class Solution {
    //this is TLE
    // int solveRec(int amount, vector<int> &coins){
    //     if(amount==0)return 0;
    //     if(amount<0)return INT_MAX;
    //     int temp=INT_MAX;
    //     for(int c:coins){
    //         int x=solveRec(amount-c,coins);
    //         if(x!=INT_MAX) temp=min(temp,x+1);
    //     }
    //     return temp;
    // }

    
    // int solveMemo(int amount, vector<int> &coins,vector<int> &dp){
    //     if(amount==0)return 0;
    //     if(amount<0)return INT_MAX;
    //     if(dp[amount]!=-1)return dp[amount];
    //     int temp=INT_MAX;
    //     for(int c:coins){
    //         int x=solveMemo(amount-c,coins,dp);
    //         if(x!=INT_MAX) temp=min(temp,x+1);
    //     }
    //     dp[amount]=temp;
    //     return temp;
    // }

    
public:
    int coinChange(vector<int>& coins, int amount) {
        int ans;
        //recursion 
        // ans = solveRec(amount, coins);

        //memo
        // vector<int> dp(amount+1,-1);
        // ans=solveMemo(amount,coins,dp);

        //tabulization
        vector<int> dp(amount+1,INT_MAX);
        dp[0]=0;
        for(int x=1;x<=amount;x++){
            for(int c:coins){
                if(x>=c && dp[x-c]!=INT_MAX) dp[x]=min(dp[x],1+dp[x-c]);
            }
        }
        ans=dp[amount];
        return ans == INT_MAX ? -1 : ans;

    }
};
