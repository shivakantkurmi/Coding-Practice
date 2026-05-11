// User function Template for C++

class Solution {
  public:
    string betterString(string &s1, string &s2) {
        // code here
        vector<int> last(26,0);//stores the total subsequence count at occurance of ch
        int total1=1;//base case empty array
        for(char ch:s1){
            int newTotal= 2*total1-last[ch-'a'];//if ch is new then last[ch]=0
            last[ch-'a']=total1;
            total1=newTotal;
        }
        int total2=1;//base case empty array
        vector<int> last2(26,0);
        for(char ch:s2){
            int newTotal= 2*total2-last2[ch-'a'];
            last2[ch-'a']=total2;
            total2=newTotal;
        }
        if(total1>=total2) return s1;
        return s2;
        
    }
};
