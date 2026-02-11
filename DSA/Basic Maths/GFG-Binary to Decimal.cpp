class Solution {
  public:
    int binary_to_decimal(int B) {
        // Code here
        string s=to_string(B);
        int ans=0;
        for(int i=s.size()-1;i>=0;i--){
            if(s[i]=='1')
             ans+=(pow(2,s.size()-1-i));
        }
        return ans;
    }
};
