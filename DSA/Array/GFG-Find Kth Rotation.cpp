//Link : https://www.geeksforgeeks.org/problems/rotation4723/1

class Solution {
  public:
    int findKRotation(vector<int> &arr) {
        // Code Here
        int k=0;
        int n=arr.size();
        if(arr[0]<arr[n-1])return 0;
        for(int i=0;i<n-1;i++){
            k++;
            if(arr[i]>arr[i+1])break;
        }
        return k;
    }
};
