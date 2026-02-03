//Link : https://www.geeksforgeeks.org/problems/buy-stock-2/1

class Solution {
  public:
    int maxProfit(vector<int> &prices) {
        // code here
        int buy=prices[0],maxProfit=0;
        for(int i : prices){
            buy=min(buy,i);
            maxProfit=max(maxProfit,i-buy);
        }
        return maxProfit;
    }
};
