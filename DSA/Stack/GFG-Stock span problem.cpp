//Link : https://www.geeksforgeeks.org/problems/stock-span-problem-1587115621/1

class Solution {
  public:
    vector<int> calculateSpan(vector<int>& arr) {
        // code here
        stack<pair<int,int>> st;
        int span=1;
        vector<int> ans;
        for(int i:arr){
            while(!st.empty() && i>=st.top().first){
                span+=st.top().second;
                st.pop();
            }
            st.push({i,span});
            ans.push_back(span);
            span=1;
        }
        
        return ans;
    }
};
