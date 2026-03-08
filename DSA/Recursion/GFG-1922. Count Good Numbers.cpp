class Solution {
public:
    const long long MOD = 1000000007;

    long long myPow(long long b, long long n){
        if(n==0) return 1;

        long long half = myPow(b, n/2) % MOD;

        if(n%2==0)
            return (half * half) % MOD;
        else
            return (b * half % MOD * half % MOD) % MOD;
    }

    int countGoodNumbers(long long n) {

        // even pos possible values =5
        // odd pos possible value=4
        //total arrengement repetition allowed= 5^ciel(n/2)*4^floor(n/2)
        // as 0 based indexing so when odd n then even have one more place that's why even is ceil and odd is floor
        long long even = (n+1)/2;
        long long odd = n/2;

        long long v1 = myPow(5, even);
        long long v2 = myPow(4, odd);

        return (v1 * v2) % MOD;
    }
};
