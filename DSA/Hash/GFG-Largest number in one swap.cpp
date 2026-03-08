class Solution {
  public:
    string largestSwap(string &s) {
        // code here
        vector<int> mp(10,0);
        for(char c:s)mp[c-'0']++;
        int x=9;
        char v='#';
        for(int i=0;i<s.length();i++){
            while(mp[x]==0)x--;
            if(s[i]-'0'!=(x)){
                v=s[i];
                s[i]=(char)(x+'0');
                break;
            }
            else mp[x]--;
        }
        if(v=='#') return s;
        for(int i=s.length()-1;i>=0;i--){
            if(s[i]-'0'==(x)) {
                s[i]=v;
                break;
            }
        }
        return s;
    }
};
