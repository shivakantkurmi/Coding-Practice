class Solution {
  public:
    int coin(vector<int>& arr) {
        // code here
        int start=0,end=arr.size()-1;
        while(start<end){
            if(arr[start]<=arr[end])end--;
            else start++;
        }
        return arr[start];
    }
};
