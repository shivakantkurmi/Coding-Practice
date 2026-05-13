class Solution {
    int search(int l, int r, int n,int m){
        while(l<=r){
            int mid=l+(r-l)/2;
            int x=pow(mid,n);
            if(x==m) return mid;
            else if(x<m)l=mid+1;
            else r=mid-1;
        }
        return -1;
    }
  public:
    int nthRoot(int n, int m) {
        // Code here
        if(n==1) return m;
        return search(0,m,n,m);
        
    }
};
