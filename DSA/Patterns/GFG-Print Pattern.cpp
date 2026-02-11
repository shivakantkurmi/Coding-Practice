//Link : https://www.geeksforgeeks.org/problems/print-pattern3549/1?page=1&category=CPP,pattern-printing&status=unsolved,attempted&sortBy=submissions

class Solution {
  public:
    vector<int> pattern(int n) {
        // code here
        if(n<=0)return {n};
        vector<int>ans;
        int temp=n;
        while(temp>0){
            ans.push_back(temp);
            temp-=5;
        }
        while(temp<=n){
            ans.push_back(temp);
            temp+=5;
        }
        return ans;
    }
};
