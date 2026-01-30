class Solution {
public:
    int mySqrt(int x) {
        int l=0,h=x,ans;
        while(l<=h){
            int m = (l+h)/2;
            long long  m_sq = (long long)m*m;
            if (m_sq == x)  
                return m;
            else if (m_sq < x){  
                ans = m;
                l = m + 1;
            }
            else       
                h = m-1;
        }
        return ans;
    }
};
