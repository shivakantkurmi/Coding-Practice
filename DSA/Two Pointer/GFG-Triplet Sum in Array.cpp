
class Solution {
  public:
    bool hasTripletSum(vector<int> &arr, int target) {
        // Your Code Here
        int n=arr.size();
        sort(arr.begin(),arr.end());
        for(int i=0;i<n;i++){
            int l=i+1,r=n-1;
            while(l<r){
                int t=arr[i]+arr[l]+arr[r];
                if(t==target) return true;
                else if(t>target)r--;
                else l++;
            }
        }
        return false;
    }
};

