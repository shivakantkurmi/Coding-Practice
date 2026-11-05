class Solution {
  public:
    int getMinimumDays(string &s, vector<int> &p) {
        // code here
        int cnt=0;
        int n=s.size();
        for(int i=1;i<n;i++){
            if(s[i]==s[i-1])cnt++;
        }
        if(cnt==0)return 0;
        int days=1;
        for(auto i:p){
            // s[i]='?';
            if(i>0 && s[i]==s[i-1]){
                cnt--;
            }
            if(i<n-1 && s[i]==s[i+1])cnt--;
            s[i]='?';
            if(cnt==0)return days;
            days++;
        }
        return -1;
    }
};
