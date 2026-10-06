class Solution {
  public:
    int longIncPath(vector<vector<int>> &matrix, int n, int m) {
        // code here
        vector<vector<int>>path(n, vector<int>(m , 1));
        int arr[] = {-1,  0, 1 , 0 , -1};
        auto isInside = [&](int x , int y){
            return x>=0 && y>=0 && x<n && y<m;
        };
        vector<int>vec(n * m);
        for(int i = 0 ;i<n*m ; i++){
            vec[i] = i;
        }
        sort(vec.begin() , vec.end() , [&](int a , int b){
           return matrix[a/m][a%m] < matrix[b/m][b%m]; 
        });
        int ans = 1;
        int x , y ,i , j;
        for(auto &val: vec){
            i = val/m , j = val%m;
            ans = max(ans , path[i][j]);
            for(int k = 0 ;k<4 ; k++){
                x  = i + arr[k] , y = j + arr[k+1];
                if(isInside(x , y) && matrix[x][y] > matrix[i][j]){
                    path[x][y] = max(path[x][y] , path[i][j] +1);
                }
            }
        }
        return ans;
    }
};
