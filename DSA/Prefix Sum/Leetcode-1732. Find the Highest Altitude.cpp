class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int ans=INT_MIN,x=0;
        for(int i:gain){
            x+=i;
            ans=max(ans,x);
        }
        return ans>=0?ans:0;
    }
};
