class Solution {
public:
    int hIndex(vector<int>& citations) {
        int maxi=*max_element(citations.begin(),citations.end());
        vector<int> count(maxi+1,0);
        for(int i:citations) count[i]++;
        for(int i=maxi;i>0;i--){
            count[i-1]+=count[i];
            if(count[i]>=i)return i;
        }
        return citations[0];

    }
};
