class Solution {
  public:
    vector<int> find(vector<int>& arr, int x) {
        // code here
        int n=arr.size();
        int l=lower_bound(arr.begin(),arr.end(),x)-arr.begin();
        if(l==n || arr[l]!=x)return {-1,-1};//if not found in array 
        int r=(upper_bound(arr.begin(),arr.end(),x)-arr.begin())-1;
        return{l,r};
    }
};
