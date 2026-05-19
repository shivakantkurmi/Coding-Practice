class Solution {
    void mergeSort(vector<pair<int,int>> &a, int l, int r, vector<int> &ans) {
        if(l >= r) return;

        int m = l + (r - l) / 2;

        mergeSort(a, l, m, ans);
        mergeSort(a, m + 1, r, ans);

        vector<pair<int,int>> t;

        int i = l;
        int j = m + 1;

        int cnt = 0;

        while(i <= m && j <= r) {

            if(a[j].first < a[i].first) {
                cnt++;
                t.push_back(a[j++]);
            }
            else {
                ans[a[i].second] += cnt;
                t.push_back(a[i++]);
            }
        }

        while(i <= m) {
            ans[a[i].second] += cnt;
            t.push_back(a[i++]);
        }

        while(j <= r) {
            t.push_back(a[j++]);
        }

        for(int k=l;k<=r;k++) {
            a[k] = t[k-l];
        }
    }

public:
    vector<int> countSmaller(vector<int>& nums) {

        int n = nums.size();

        vector<pair<int,int>> a;

        for(int i=0;i<n;i++) {
            a.push_back({nums[i], i});
        }

        vector<int> ans(n,0);

        mergeSort(a,0,n-1,ans);

        return ans;
    }
};
