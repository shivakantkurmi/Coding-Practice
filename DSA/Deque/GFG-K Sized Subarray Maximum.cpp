//Link : https://www.geeksforgeeks.org/problems/maximum-of-all-subarrays-of-size-k3101/1


class Solution {
  public:
    vector<int> maxOfSubarrays(vector<int>& arr, int k) {
        deque<int> qu;
        vector<int> ans;
        for(int i = 0; i < arr.size(); i++) {
            while(!qu.empty() && qu.back() < arr[i]) qu.pop_back();
            qu.push_back(arr[i]);
            
            if(i >= (k - 1)) {
                ans.push_back(qu.front());
                if(arr[i - k + 1] == qu.front()) qu.pop_front();
            }
        }
        
        return ans;
    }
};

