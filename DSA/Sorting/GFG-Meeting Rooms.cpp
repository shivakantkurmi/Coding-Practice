// Link : https://www.geeksforgeeks.org/problems/attend-all-meetings/1

class Solution {
  public:
    bool canAttend(vector<vector<int>> &arr) {
        // Code Here
        sort(arr.begin(),arr.end());
        for(int i=0;i<arr.size()-1;i++){
            // cout<<arr[i][0]<<arr[i][1];
            if(arr[i][1]>arr[i+1][0])return false;
        }
        return true;
    }
};
