class Solution {
  public:
    int intersectSize(vector<int> &a, vector<int> &b) {
        // code  here
        unordered_set<int> mp(a.begin(),a.end());
        int count=0;
        for(int i:b){
            if(mp.find(i)!=mp.end())count++;
        }
        return count;
    }
};
