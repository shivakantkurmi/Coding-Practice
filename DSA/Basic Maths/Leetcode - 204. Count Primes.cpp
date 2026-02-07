// count prime that are strictly less than n

class Solution {
public:
    int countPrimes(int n) {
        int prime=0;
        vector<bool> p(n+1,1);
        p[0]=0,p[1]=0;
        for(int i=2;i*i<=n;i++){
            if(p[i]==1){
                for(int j=i*i;j<=n;j+=i){
                    p[j]=0;
                }
            }
        }
        p[n]=0;
        for(bool i : p){
            if(i) prime++;
        }
        return prime;
    }
};
