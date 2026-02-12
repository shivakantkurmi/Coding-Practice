class Solution {
  public:
    // Function to delete middle element of a stack.
    void deleteMid(stack<int>& s) {
        // code here..
        int n=s.size();
        int mid=n/2;
        int cnt=0;
        while(!s.empty()){
            if(cnt==mid) s.pop();
            else {
                cout<<s.top()<<" ";
                s.pop();
            }
            cnt++;
        }
        
    }
};
