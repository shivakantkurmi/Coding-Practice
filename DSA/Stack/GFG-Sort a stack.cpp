class Solution {
  public:
    void sortStack(stack<int> &st) {
        // code here
        vector<int> temp;
        while(!st.empty()){
            temp.push_back(st.top());
            st.pop();
        }
        sort(temp.begin(),temp.end());
        for(int i:temp)st.push(i);
    }
};
