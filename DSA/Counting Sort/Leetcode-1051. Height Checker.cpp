class Solution {
public:
    int heightChecker(vector<int>& heights) {
        vector<int> count(101, 0);

        // Count frequency
        for(int h : heights)
            count[h]++;

        int idx = 0;
        int mismatch = 0;

        // Simulate sorted array
        for(int h = 1; h <= 100; h++){
            while(count[h]--){
                if(heights[idx] != h)
                    mismatch++;
                idx++;
            }
        }

        return mismatch;
    }
};
