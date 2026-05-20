class Solution {
public:
    bool isProduct(vector<int>& arr, long long target) {
        unordered_map<long long,int> mp;

        for(long long x : arr){

            if(x == 0){
                if(target == 0 && mp[0] > 0)
                    return true;
            }
            else{
                if(target % x == 0){
                    long long y = target / x;

                    if(mp.count(y))
                        return true;
                }
            }

            mp[x]++;
        }

        return false;
    }
};
