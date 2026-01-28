class Solution {
private:
    int gcd(int a,int b){
        if(b==0) return a;
        else return gcd(b,a%b);
    }
public:
    string gcdOfStrings(string str1, string str2) {
        if (str1 + str2 != str2 + str1) {
            return "";
        }
        int n=str1.size(),m=str2.size();
        int g=gcd(m,n);
        return str1.substr(0,g);
    }
};
