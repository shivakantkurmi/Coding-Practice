class Solution {
  public:
    bool checkEqual(vector<int>& a, vector<int>& b) {
        // code here
        unordered_map<int,int> mp;
        for(int i:a)mp[i]++;
        for(int i:b){
            if(mp[i]<=0) return false;
            mp[i]--;
        }
        return true;
    }
};
