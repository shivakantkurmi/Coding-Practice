class Solution {
public:
    int binaryGap(int n) {
        int ans=0;
        bool start=false;
        int i=-1,j=0;
        while(n!=0){
            if((n&1)==1){
                if(start){
                    ans=max(j-i,ans);
                    i=j;
                }
                else {
                    start=1;
                    i=j;
                }
            }
            n=n>>1;
            j++;
        }
        return ans;
    }
};
