class Solution {
  public:
    
    void insertSorted(stack<int>& st, int x){
        if(st.empty() || st.top() <= x){
            st.push(x);
            return;
        }
        
        int t = st.top();
        st.pop();
        
        insertSorted(st, x);
        
        st.push(t);
    }
    
    void sortStack(stack<int> &st) {
        if(st.empty()) return;
        int t = st.top();
        st.pop();
        
        sortStack(st);
        
        insertSorted(st, t);
    }
};


//using while loop
class Solution {
  public:
    
    void sortStack(stack<int> &st) {
        stack<int> temp;
        
        while(!st.empty()){
            int x = st.top();
            st.pop();
            
            while(!temp.empty() && temp.top() < x){
                st.push(temp.top());
                temp.pop();
            }
            
            temp.push(x);
        }
        
        while(!temp.empty()){
            st.push(temp.top());
            temp.pop();
        }
    }
};
