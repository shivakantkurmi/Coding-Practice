
class Solution {
  public:
    int firstNonRepeating(vector<int>& arr) {
        // Complete the function
        unordered_map<int,int> mp;
        for(int i: arr){
            mp[i]++;
        }
        for(int i:arr){
            if(mp[i]==1)return i;
        }
        return 0;
    }
};
