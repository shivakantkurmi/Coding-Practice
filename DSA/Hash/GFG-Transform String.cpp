class Solution {
  public:
    int transform(string A, string B) {
        
        if (A.size() != B.size())
            return -1;
        
        int n = A.size();
        
        // Step 1: Check frequency
        vector<int> freq(256, 0);
        
        for (int i = 0; i < n; i++) {
            freq[A[i]]++;
            freq[B[i]]--;
        }
        
        for (int i = 0; i < 256; i++) {
            if (freq[i] != 0)
                return -1;
        }
        
        // Step 2: Two pointer from end
        int i = n - 1;
        int j = n - 1;
        int count = 0;
        
        while (i >= 0) {
            if (A[i] == B[j]) {
                j--;
            } else {
                count++;
            }
            i--;
        }
        
        return count;
    }
};
