class Solution {
  public:
    vector<int> getMinMax(vector<int> &arr) {
        // code here
        int min=INT_MAX,max=INT_MIN;
        for(int i:arr){
            if(min>i)min=i;
            if(max<i)max=i;
        }
        return {min,max};
    }
};
