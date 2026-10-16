class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();
        // vector<vector<int>> vis(n,vector<int>(m,0));
        queue<pair<int,int>> q;
        for(int i=0;i<n;++i){
            for(int j=0;j<m;++j){
                // if(vis[i][j]) continue;
                if(mat[i][j]==0) q.push({i,j});
                else mat[i][j]=1e4;
            }
        }

        while(!q.empty()){
            int x=q.front().first;
            int y=q.front().second;
            q.pop();
            int dx[]={0,1,-1,0};
            int dy[]={-1,0,0,1};
            for(int i=0;i<4;++i){
                int nx=x+dx[i];
                int ny=y+dy[i];
                if(nx<n && ny<m && nx>=0 && ny>=0){
                    if(mat[nx][ny]>mat[x][y]+1){
                        mat[nx][ny]=mat[x][y]+1;
                        q.push({nx,ny});
                    }
                }
            }
        }
        return mat;
    }
};
