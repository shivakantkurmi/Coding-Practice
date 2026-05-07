class Solution {
  public:
  
    void insertAtBottom(stack<int>&st,int x){
        if(st.empty()){
            st.push(x);
            return ;
        }
        int t=st.top();
        st.pop();
        insertAtBottom(st,x);
        st.push(t);

    }
    void reverseStack(stack<int> &st) {
        // code here
        if(st.empty()) return;
        int t=st.top();
        st.pop();
        reverseStack(st);
        insertAtBottom(st,t);
    }
};

//using while loop
class Solution {
  public:
    void reverseStack(stack<int> &st) {
        vector<int> v;
        
        while(!st.empty()){
            v.push_back(st.top());
            st.pop();
        }
        
        for(int x : v)
            st.push(x);
    }
};
