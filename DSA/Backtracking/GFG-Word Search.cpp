using vvc=vector<vector<char>>;
using vvi=vector<vector<int>>;
class Solution {
  public:
    vvi dirs={
        {-1,0},{0,1},{1,0},{0,-1}
    };
    
    bool helper(int r,int c,vvc &mat,int idx,string &word){
        int n=mat.size(),m=mat[0].size();
        if(idx==word.size()-1) return true;
        // visited
        char prev=mat[r][c];
        mat[r][c]='$';
        auto isValid=[&](int i,int j){
            return (i>=0 && i<n && j>=0 && j<m && mat[i][j]!='$');
        };
        idx++;
        bool ans=false;
        for(int dir=0;dir<4;dir++){
            int nr=r+dirs[dir][0],nc=c+dirs[dir][1];
            if(isValid(nr,nc) && mat[nr][nc]==word[idx]){
                if(helper(nr,nc,mat,idx,word))return true;
            }
        }
        mat[r][c]=prev;
        return false;
    }
    bool isWordExist(vector<vector<char>> &mat, string &word) {
        // Code here
        int n=mat.size(),m=mat[0].size();
        bool ans=false;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(word[0]==mat[i][j] && 
                helper(i,j,mat,0,word)) return true;
            }
        }
        return false;
    }
};
