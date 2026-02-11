class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        int maxi=*max_element(costs.begin(),costs.end());
        vector<int>count(maxi+1,0);
        int ans=0;
        for(int i:costs)count[i]++;
        for(int i=0;i<=maxi;i++){
            while(count[i]--){
                if(coins==0)return ans;
                if(coins>=i)coins-=i,ans++;
            }
        }
        return ans;
    }
};
