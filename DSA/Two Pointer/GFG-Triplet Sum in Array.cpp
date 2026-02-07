// this have TC - O(n^2) and SC - O(1)
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

// this have TC - O(n^2) and SC - O(n)
// class Solution {
//   public:
//     bool hasTripletSum(vector<int> &arr, int k) {
//         // Code Here
//         int n = arr.size();

//         for(int i=0;i<n;i++){
//             unordered_set<int> st;
//             int target = k - arr[i];
    
//             for(int j=i+1;j<n;j++){
//                 int need = target - arr[j];
    
//                 if(st.count(need))
//                     return true;
    
//                 st.insert(arr[j]);
//             }
//         }
//         return false;
//     }
// };

