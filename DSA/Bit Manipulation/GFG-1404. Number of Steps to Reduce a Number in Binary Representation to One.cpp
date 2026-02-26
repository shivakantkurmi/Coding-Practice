class Solution {
public:
    int numSteps(string s) {
        int steps = 0, carry = 0;

        for(int i = s.size()-1; i > 0; i--) {
            if((s[i]-'0'+carry)%2==1){
                steps += 2;
                carry = 1;
            }
            else steps += 1;
        }
        return steps + carry;
    }
};

// class Solution {
// public:
//     int numSteps(string s) {
//         int ans=0;
//         while(s.length()!=1){
//             int n=s.length()-1;
//             if(s[n]=='0') s.pop_back();
//             else {
//                 s[n]='0';
//                 bool c=1;
//                 for(n=n-1;n>=0;n--){
//                     if(s[n]=='1' && c)s[n]='0';
//                     else {
//                         s[n]='1',c=0;
//                         break;
//                     }
//                 }
//                 if(c)s='1'+s;
//             }
//             ans++;
//         }
//         return ans;
//     }
// };

