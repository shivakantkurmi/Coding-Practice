class Solution {
public:
    vector<int> commonElements(vector<int> &a, vector<int> &b) {
        int maxA = *max_element(a.begin(), a.end());
        int maxB = *max_element(b.begin(), b.end());
        int mx = max(maxA, maxB);

        vector<int> count(mx+1, 0), count2(mx+1, 0);

        for(int x : a) count[x]++;
        for(int x : b) count2[x]++;

        vector<int> ans;

        for(int i = 0; i <= mx; i++){
            int freq = min(count[i], count2[i]);
            while(freq--){
                ans.push_back(i);
            }
        }

        return ans;
    }
};
