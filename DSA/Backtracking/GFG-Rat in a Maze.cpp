class Solution {
    vector<string> paths;
    void generatePaths( vector<int> pos, int n, vector<vector<int>>& mat, vector<vector<int>> &visited, string s){
        if(pos[0]==n-1 && pos[1]==n-1){
            paths.push_back(s);
            return;
        }
        //move downward
        if(pos[0]!=n-1){    
                pos[0]+=1;
                if(mat[pos[0]][pos[1]]!=0 && visited[pos[0]][pos[1]]==0) {
                    visited[pos[0]][pos[1]]=1;
                    generatePaths( pos, n, mat,visited, s+'D');
                    visited[pos[0]][pos[1]]=0;
                    
                }
                pos[0]-=1;
        }
        
        //move left
        if(pos[1]!=0){
                pos[1]-=1;
                if(mat[pos[0]][pos[1]]!=0 && visited[pos[0]][pos[1]]==0) {
                    visited[pos[0]][pos[1]]=1;
                    generatePaths( pos, n, mat,visited, s+'L');
                    visited[pos[0]][pos[1]]=0;
                    
                }
                pos[1]+=1;
        }
        
        //Move Right
        if(pos[1]!=n-1){
                pos[1]+=1;
                if(mat[pos[0]][pos[1]]!=0 && visited[pos[0]][pos[1]]==0) { 
                    visited[pos[0]][pos[1]]=1;
                    generatePaths( pos, n, mat,visited, s+'R');
                    visited[pos[0]][pos[1]]=0;
                }
                pos[1]-=1;
        }
        
        //move upward
        if(pos[0]!=0){
                pos[0]-=1;
                if(mat[pos[0]][pos[1]]!=0 && visited[pos[0]][pos[1]]==0){
                    visited[pos[0]][pos[1]]=1;
                    generatePaths(pos, n, mat,visited, s+'U');
                    visited[pos[0]][pos[1]]=0;
                    
                }
                pos[0]+=1;
        }

      
        return;
        
    }
  public:
    vector<string> ratInMaze(vector<vector<int>>& maze) {
        // code here
        if(maze[0][0]==0)return paths;
        vector<int>pos={0,0};
        int n=maze.size();
        vector<vector<int>> visited(n,vector<int>(n,0));
        visited[0][0]=1;
        generatePaths(pos,n,maze,visited,"");
        return paths;
    }
};
