class Solution {
  public:
      int digS(int d){
        int x=0;
        while(d>0){
            x+=d%10;
            d/=10;
        }
        return x;
    }
    int getCount(int n, int d) {
        // code here
        int x=d;
        d=ceil(floor(d)/10)*10;
        while(d%10!=0 || (d-digS(d))<x)d+=10;
        if(n-d+1>0)return n-d+1;
        else return 0;
    }
};


//Binary search logic

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
