class Solution {
  public:
    vector<vector<int>> levelSort(vector<int>& arr) {
           vector<vector<int>>ans;
           
           int n=arr.size();
           int index=0;
           
           int levelsize=1;
           
           while(index<n){
               vector<int>lev;
               for(int i=0;i<levelsize && index<n;i++){
                   lev.push_back(arr[index]);
                   index++;
               }
               sort(lev.begin(),lev.end());
               ans.push_back(lev);
               levelsize*=2;
           }
           return ans;
    }
}; 
