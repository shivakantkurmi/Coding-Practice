class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        long long sum = 0;
        for(auto &row : grid)
            for(int val : row)
                sum += val;

        if(sum % 2 != 0) return false;

        // Vertical cut
        long long tsum = 0;
        for(int col = 0; col < n; col++){
            for(int row = 0; row < m; row++){
                tsum += grid[row][col];
            }
            if(tsum * 2 == sum) return true;
        }

        // Horizontal cut
        tsum = 0;
        for(int row = 0; row < m; row++){
            for(int col = 0; col < n; col++){
                tsum += grid[row][col];
            }
            if(tsum * 2 == sum) return true;
        }

        return false;
    }
};
