// class Solution {
// public:
//     int hIndex(vector<int>& c) {
//         int n = c.size();
//         for(int i = n; i >= 0; i--) {
//             int idx = lower_bound(c.begin(), c.end(), i) - c.begin();

//             if(n - idx >= i)
//                 return i;
//         }
//         return 0;
//     }
// };

class Solution {
public:
    int hIndex(vector<int>& c) {
        int n = c.size();
        int l = 0, r = n - 1;

        while(l <= r) {
            int m = l + (r - l) / 2;
            if(c[m] >= n - m)
                r = m - 1;
            else
                l = m + 1;
        }

        return n - l;
    }
};
