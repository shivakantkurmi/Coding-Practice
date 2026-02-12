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


// 2nd way using counting sort (tc- O(n) and SC- O(n) )
class Solution {
  public:
    void sortStack(stack<int> &st) {
        // code here
        vector<int> temp;
        while(!st.empty()){
            temp.push_back(st.top());
            st.pop();
        }
        vector<int> count(1000+1,0);
        for(int i:temp)count[i]++;
        for(int i=0;i<1001;i++){
            while(count[i]--)
                    st.push(i);
        }
    }
};
