class Solution {
    vector<int> dirs={0,1,0,-1,0};
    void dfs(int x,int y,vector<vector<int>> &grid,vector<vector<bool>> &vis,int m,int n){
        vis[x][y]=1;
        for(int d=0;d<4;d++){
            int x1=x+dirs[d],y1=y+dirs[d+1];
            if(x1>=0&&x1<m&&y1>=0&&y1<n&&!vis[x1][y1]&&grid[x1][y1]) dfs(x1,y1,grid,vis,m,n);
        }
    }
    int c(vector<vector<int>> &grid,int m,int n){
        int count=0;
        vector<vector<bool>> vis(m,vector<bool>(n));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(!vis[i][j]&&grid[i][j]){
                    dfs(i,j,grid,vis,m,n);
                    count++;
                }
            }
        }
        return count;
    }
public:
    int minDays(vector<vector<int>>& grid) {
        int m=grid.size(),n=grid[0].size();
        int count=c(grid,m,n);
        if(count!=1) return 0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]){
                    grid[i][j]=0;
                    count=c(grid,m,n);
                    grid[i][j]=1;
                    if(count!=1) return 1;
                }
            }
        }
        return 2;
    }
};