//Link :  https://www.geeksforgeeks.org/problems/remove-k-digits/1



class Solution {
  public:
    string removeKdig(string &s, int k) {
        // code here
        stack<char> st;
        int i=0,n=s.size();
        for(char c:s){
            char t=c;
            while(!st.empty() && k>0 && st.top()>t){
                st.pop();
                k--;
            }
            st.push(t);
        }
        while(k>0)st.pop(),k--;
        string minNum="";
        while(!st.empty()){
            minNum.push_back(st.top());
            st.pop();
        }
        reverse(minNum.begin(), minNum.end());

        string final="";
        i=0,n=minNum.length();
        while(i<n && minNum[i]=='0')i++;
        while(i<n)final+=minNum[i++];
    
        return (final==""?"0":final);
    }
};
