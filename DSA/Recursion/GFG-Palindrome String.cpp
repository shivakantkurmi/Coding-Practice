class Solution {
  public:
    bool recPal(string &s,int i,int j){
        if(j<=i)return true;
        return s[i]==s[j] && recPal(s,i+1,j-1);
        
    }
    bool isPalindrome(string& s) {
        // code here
        // int i=0,j=s.length()-1;
        // while(i<=j){
        //     if(s[i++]!=s[j--])return false;
        // }
        // return true;
        
        return recPal(s,0,s.size()-1);
    }
};
