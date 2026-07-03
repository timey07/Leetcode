class Solution {
private:
    void dfs(vector<vector<int>>& grid,vector<vector<int>>& vis,int a,int b,int m,int n){
        vis[a][b]=1;

        int dx[]={-1,0,1,0};
        int dy[]={0,-1,0,1};
        for(int i=0;i<4;++i){
            int x=a+dx[i];
            int y=b+dy[i];

            if(x>=0 && y>=0 && x<m && y<n && !vis[x][y] && grid[x][y]==1){
                dfs(grid,vis,x,y,m,n);
            }
        }
    }   
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>> vis(m,vector<int>(n,0));

        for(int i=0;i<m;++i){
            if(!vis[i][0] && grid[i][0]==1) dfs(grid,vis,i,0,m,n);
            if(!vis[i][n-1] && grid[i][n-1]==1) dfs(grid,vis,i,n-1,m,n);
        }

        for(int j=0;j<n;++j){
            if(!vis[0][j] && grid[0][j]==1) dfs(grid,vis,0,j,m,n);
            if(!vis[m-1][j] && grid[m-1][j]==1) dfs(grid,vis,m-1,j,m,n);
        }

        int ans=0;
        for(int i=1;i<m-1;++i){
            for(int j=1;j<n-1;++j){
                if(!vis[i][j] && grid[i][j]==1) ans++;
            }
        }
        return ans;
    }
};
