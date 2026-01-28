// C++ program to check if we can get
// d litre water in one of the two jugs
// its only possible if d>m and d> n and also d is divisible by gcd(m,n)
#include <bits/stdc++.h>
using namespace std;
int gcd(int m, int n)
{
    if (n == 0)
       return m;
    return gcd(m, m % n);
}

bool isFeasible(int m, int n, int d){

    if (d > n && d > m)
        return false;
    return ((d % gcd(m, n)) == 0);
}

int main()
{
    int n = 3, m = 5, d = 4;
    cout << isFeasible(m, n, d);
    return 0;
}

//2nd varient is the combined water in both jug should be d like if one jug has 2L and another has 3L then combined will be 5L
//can be solved with above approach just check d>(m+n) and d%(gcd(m,n))==0;
// bool isFeasible(int m, int n, int d){
//     if (d > (n + m))
//         return false;
//     return ((d % gcd(m, n)) == 0);
// }
