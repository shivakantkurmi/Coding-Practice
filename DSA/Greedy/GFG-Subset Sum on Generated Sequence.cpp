class Solution {
  public:
    bool isPossible(vector<int>& arr, int s, int x) {
        // code here
        vector<long long> allSeq;
        allSeq.push_back(s);
        long long sum = s;
        
        for (long long num : arr) {
            
            long long newNum = sum + num;
            int b = x - newNum;
            
            if (newNum > x) break;
            
            allSeq.push_back(newNum);
            
            sum += newNum;
        }
        
        for (int i = allSeq.size()-1; i >= 0; i--) {
            
            if (allSeq[i] <= x) {
                x -= allSeq[i];
            }
            
            if (x == 0) return true;
        }
        
        return false;
    }
};

