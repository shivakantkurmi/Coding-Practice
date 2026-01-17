//link : https://www.geeksforgeeks.org/problems/expression-contains-redundant-bracket-or-not/1

class Solution {
  public:
    bool checkRedundancy(string &s) {
        // code here
        bool op=0;
        stack<char> st;
        for(char c:s){
            st.push(c);
            while(st.top()==')'){
                st.pop();
                while(!st.empty() && st.top()!='(') {
                    if(st.top()=='+'||st.top()=='-'||st.top()=='*'||st.top()=='/') op=true;
                    st.pop();
                }
                st.pop();
                if(!op)return true;
                st.push('z');
                op=false;
            }
        }
        return false;
    }
};
