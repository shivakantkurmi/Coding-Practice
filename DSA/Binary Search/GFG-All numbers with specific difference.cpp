// link : https://www.geeksforgeeks.org/problems/all-numbers-with-specific-difference3558/1

class Solution {
  public:
    int value(int n){
        int t=n,s=0;
        while(t){
            s+=(t%10);
            t/=10;        
        }
        return n-s;
    }
    int getCount(int n, int d) {
        // code here
        if(d>=n || n<10)return 0;
        int l=10,r=n;
        int ans=0;
        while(l<=r){
            int mid=l+(r-l)/2;
            if(value(mid)>=d){
                ans=n-mid+1;
                r=mid-1;
            }
            else l=mid+1;
            // cout<<start<<" "<<mid<<endl;
        }
        return ans;
    }
};
