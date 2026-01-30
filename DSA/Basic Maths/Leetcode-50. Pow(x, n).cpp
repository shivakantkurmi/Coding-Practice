class Solution {
public:
    double myPow(double x, int n) {
        if(n==0)return 1;
        else if(n<0) return 1/(x*pow(x,-(n+1)));
        else{ 
            // if(n%2!=0) return x*(pow(x,n-1));
            // else return pow(x,n/2)*pow(x,n/2);
            if(n%2==0) return pow(x*x,n/2);
            else return x*pow(x*x,n/2);
        }
    }
};
