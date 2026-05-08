class Solution {
public:
    vector<vector<string>> ans;

    bool isSafe(vector<int>& x, int k, int i) {
        for(int j = 0; j < k; j++) {
            if(x[j] == i || abs(x[j] - i) == abs(j - k))
                return false;
        }
        return true;
    }

    void Nqueen(vector<int>& x, int k, int n) {//k represent current row 
        for(int i = 0; i < n; i++) { //all posiible row check
            if(isSafe(x, k, i)) {//kth queen (row) ko ith column main rakhne ka check kar rahe hai
                x[k] = i;
                if(k == n - 1) {//if curret queen is last queen then create board and put queen position this one of solution
                    vector<string> board(n, string(n, '.'));
                    for(int r = 0; r < n; r++) {
                        board[r][x[r]] = 'Q';
                    }
                    ans.push_back(board);
                }
                else {
                    //if not last quen then now move for other queen (row)
                    Nqueen(x, k + 1, n);
                }
            }
        }
        return;//backtrack to previous  no possible solution for current placing
    }

    vector<vector<string>> solveNQueens(int n) {

        vector<int> x(n);

        Nqueen(x, 0, n);

        return ans;
    }
};
