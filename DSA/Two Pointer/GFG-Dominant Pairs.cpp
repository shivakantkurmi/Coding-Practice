class Solution {
  public:
    int dominantPairs(vector<int> &arr){
     // Code here
     int n=arr.size();
     vector<int> a,b;
     for(int i=0;i<n/2;i++)
     {
         a.push_back(arr[i]);
     }
     for(int i=n/2;i<n;i++)
     {
         b.push_back(5*arr[i]);
     }
     sort(a.begin(),a.end());
     sort(b.begin(),b.end());

     int i=a.size()-1;
     int j=b.size()-1;
     int ans=0;

     while(i>=0 && j>=0)
     {
         if(a[i]>=b[j])
         {
             ans+=(j+1);
             i--;
         }
         else
             j--;

     }
     return ans;

 } 


};
