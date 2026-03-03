class Solution {
  public:
    int totalElements(vector<int> &arr) {
        ios::sync_with_stdio(false);
        cin.tie(NULL);

        unordered_map<int,int> mp;
        int dist = 0;
        int ans = 0;
        int l = 0;

        for(int i = 0; i < arr.size(); i++) {
            if(++mp[arr[i]] == 1) dist++;

            while(dist > 2) {
                if(--mp[arr[l]] == 0) dist--;
                l++;
            }

            ans = max(ans, i - l + 1);
        }

        return ans;
    }
};
