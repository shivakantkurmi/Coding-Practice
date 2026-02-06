class Solution {
  public:
    
    vector<int> smallestDiff(vector<int>& a, vector<int>& b, vector<int>& c) {
        // code here.
        sort(a.begin(),a.end());
        sort(b.begin(),b.end());
        sort(c.begin(),c.end());
        int i=0,j=0,k=0;
        vector<int>ans(3,-1);
        int diff=INT_MAX;
        while(i<a.size() && j<b.size() && k<c.size()){
            int mini=min({a[i],b[j],c[k]});
            int maxi=max({a[i],b[j],c[k]});
            int d=maxi-mini;
            if(d==0)return {a[i],b[j],c[k]};
            if(d<diff){
                diff=d;
                ans={a[i],b[j],c[k]};
            }
            if(mini==a[i])i++;
            else if(mini==b[j]) j++;
            else k++;
        }
        sort(ans.begin(),ans.end(),greater<int>());
        return ans;
    }
};
