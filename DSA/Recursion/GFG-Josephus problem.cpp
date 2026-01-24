class Solution {
public:
    int josephus(int n, int k) {
        if (n == 1)
            return 1;

        return (josephus(n - 1, k) + k - 1) % n + 1;
    }
};


// ANOTHER WAY BY ITERATION
/*
int josephus(int n, int k) {
    int res = 0;  // 0-based
    
    for (int i = 1; i <= n; i++) {
        res = (res + k) % i;
    }
    
    return res + 1; 
}
*/
