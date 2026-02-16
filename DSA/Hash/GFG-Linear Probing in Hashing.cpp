class Solution {
  public:
    vector<int> linearProbing(vector<int>& arr, int m) {
        // code here
        vector<int> hash(m,-1);
        for(int i:arr){
            int key=i%m;
            if(hash[key]==-1 || hash[key]==i)hash[key]=i;
            else {
                int j=1;
                while(j<m){
                    key=(i+j)%m;
                    if(hash[key]==-1 || hash[key]==i){
                        hash[key]=i;
                        break;
                    }
                    j++;
                }
            }
        }
        return hash;
    }
};
