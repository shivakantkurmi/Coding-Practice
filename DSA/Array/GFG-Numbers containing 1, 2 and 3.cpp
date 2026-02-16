class Solution {
  public:
    bool isFollow(int n){
        while(n){
            if(n%10==0 || n%10>3)return 0;
            n/=10;
        }
        return 1;
    }
    vector<int> filterByDigits(vector<int>& arr) {
        // code here
        vector<int> ans;
        for(int i:arr){
            if(isFollow(i))ans.push_back(i);
        }
        if(ans.size()==0) return {-1};
        return ans;
    }
};
