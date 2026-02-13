class Solution {
  public:
    int getOddOccurrence(vector<int>& arr) {
        // code here
        int num=0;
        for(int i:arr){
            num^=i;
        }
        return num;
    }
};
