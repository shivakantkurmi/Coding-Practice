class Solution {
  public:
    long subarrayXor(vector<int> &arr, int k) {
        // code here
        unordered_map<int,int> _xor;
        _xor[0]=1;
        int x=0;
        int ans=0;
        for(int i:arr){
            x^=i;
            if(_xor.find(x^k)!=_xor.end()){
                ans+=_xor[x^k];
            }
            _xor[x]++;
        }
        return ans;
    }
};
