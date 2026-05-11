class Solution {
  public:
    
    void generate(int idx, int end, long long sum,
                  vector<long long>& temp, vector<int> &arr) {
        
        if(idx == end) {
            temp.push_back(sum);
            return;
        }
        
        generate(idx + 1, end, sum + arr[idx], temp, arr);
        generate(idx + 1, end, sum, temp, arr);
    }
    
    long long countSubsets( vector<int> &arr,int n, int l, int r) {
        
        vector<long long> left, right;
        
        int mid = n / 2;
        
        generate(0, mid, 0, left, arr);
        generate(mid, n, 0, right, arr);
        
        sort(right.begin(), right.end());
        
        long long cnt = 0;
        
        for(long long x : left) {
            
            long long low = l - x;
            long long high = r - x;
            
            auto it1 = lower_bound(right.begin(), right.end(), low);
            auto it2 = upper_bound(right.begin(), right.end(), high);
            
            cnt += (it2 - it1);
        }
        
        return cnt;
    }
};
