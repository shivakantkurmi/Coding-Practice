class Solution {
  public:
    void rotate(vector<int> &arr) {
        // code here
        reverse(arr.begin(),arr.end()-1);
        reverse(arr.end()-1,arr.end());
        reverse(arr.begin(),arr.end());
    }
};
