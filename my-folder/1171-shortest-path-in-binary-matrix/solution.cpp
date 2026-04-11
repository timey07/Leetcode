class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n=grid.size();
        queue<pair<int,int>> q;
        vector<vector<int>> vis(n,vector<int>(n,0));
        if(grid[0][0]==1 || grid[n-1][n-1]==1) return -1;
        if(n==1) return 1;
        int ans=0;
        q.push({0,0});
        vis[0][0]=1;
        int dx[8]={0,-1,0,1,-1,1,-1,1};
        int dy[8]={-1,0,1,0,-1,-1,1,1};
        while(!q.empty()){
            int size=q.size();
            ans++;
            while(size--){
                int x=q.front().first;
                int y=q.front().second;
                q.pop();
                for(int i=0;i<8;++i){
                    int nx=x+dx[i];
                    int ny=y+dy[i];
                    if(nx==n-1 && ny==n-1) return ans+1;
                    if(nx>=0 && nx<n && ny>=0 && ny<n && !vis[nx][ny] && grid[nx][ny]==0){
                        vis[nx][ny]=1;
                        q.push({nx,ny});
                    }
                }
            }
        }
        return -1;
    }
};
