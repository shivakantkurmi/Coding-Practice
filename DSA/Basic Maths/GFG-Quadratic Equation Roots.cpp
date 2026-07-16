#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> quadraticRoots(int a, int b, int c) {
        int d = b*b - 4*a*c;

        if (d < 0) {
            return {-1};  // imaginary roots
        }

        // Calculate roots
        double root1 = (-b + sqrt(d)) / (2.0 * a);
        double root2 = (-b - sqrt(d)) / (2.0 * a);

        // Floor the values
        int r1 = floor(root1);
        int r2 = floor(root2);

        // Return in decreasing order
        if (r1 >= r2) {
            return {r1, r2};
        } else {
            return {r2, r1};
        }
    }
};
