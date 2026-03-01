class Solution {
  public:
    void pushZerosToEnd(vector<int>& arr) {
        // code here
        int left=0,z=0;
        for(int &i:arr){
            if(i==0)z++;
            if(z>0){
                while(arr[left]!=0)left++;
                int t=arr[left];
                arr[left]=i;
                i=0;
            }
        }
        
    }
};
