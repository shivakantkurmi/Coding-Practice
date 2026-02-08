class Solution {
  public:
    vector<vector<int>> fourSum(vector<int> &arr, int target) {
        // code here
        vector<vector<int>> ans;
        sort(arr.begin(),arr.end());
        int n=arr.size();
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int nt=target-(arr[i]+arr[j]);
                int left=j+1,right=n-1;
                while(left<right){
                    int temp=arr[left]+arr[right];
                    if(temp==nt){
                        vector<int> t={arr[i],arr[j],arr[left],arr[right]};
                        if(!ans.empty() && (ans.back() == t)){}
                        else ans.push_back({arr[i],arr[j],arr[left],arr[right]});
                        while(left<right-1 && arr[left]==arr[left+1])left++;
                        left++;
 
                    }
                    else if(temp<nt)left++;
                    else right--;
                }
                while(j<n-1 && arr[j]==arr[j+1])j++;
            }
            while(i<n-1 && arr[i]==arr[i+1])i++;
        }
        return ans;
    }
};
