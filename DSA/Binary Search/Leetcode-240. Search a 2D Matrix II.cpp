class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n=matrix.size(),m=matrix[0].size();
        int row=0,col=m-1;
        while(row<n && col>=0){
            int x=matrix[row][col];
            if(x==target) return true;
            else if(x<target) row++;
            else col--;
        }
        return false;
    }
};
