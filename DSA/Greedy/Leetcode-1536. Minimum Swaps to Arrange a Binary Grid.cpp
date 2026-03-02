class Solution {
public:
    int minSwapsCount(vector<int> target) {
        int n = target.size();
        int swaps = 0;

        for(int i = 0; i < n; i++) {
            for(int j = i + 1; j < n; j++) {
                if(target[i] > target[j])
                    swaps++;
            }
        }
        return swaps;
    }
    int minSwaps(vector<vector<int>>& grid) {
        int n=grid.size();
        vector<int> correct(n,-1);
        for(int i=0;i<n;i++){
            int t=0;
            for(int j=n-1;j>0;j--){
                if(grid[i][j]==1)break;
                t++;
            }
            for(int j=0;j<n;j++){
                if(correct[j]==-1 && t>=(n-j-1) ){
                    correct[j]=i;
                    break;
                }
            }
        }
        for(int i:correct)cout<<i<<" ";
        cout<<endl;
        for(int i:correct){
            if(i==-1)return -1;
        }
        int ans=0;
        return minSwapsCount(correct);

        
    }
};
