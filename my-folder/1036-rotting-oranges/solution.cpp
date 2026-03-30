class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        queue<pair<int,int>> q;
        vector<int> x={0,1,0,-1};
        vector<int> y={1,0,-1,0};
        vector<vector<int>> vis(n,vector<int>(m,0));
        int ans=0;
        for(int i=0;i<n;++i){
            for(int j=0;j<m;++j){
                if(grid[i][j]==2)q.push({i,j});
            }
        }
                    
        int count=q.size();
        while(!q.empty()){
            while(count--){
                auto a=q.front();
                q.pop();
                for(int i=0;i<4;++i){
                    int nx=x[i]+a.first;
                    int ny=y[i]+a.second;
                    if(nx>=0 && ny>=0 && nx<n && ny<m && grid[nx][ny]==1 && !vis[nx][ny]){
                        vis[nx][ny]=1;
                        grid[nx][ny]=2;
                        q.push({nx,ny});
                        
                        }
                        
                    }
                    }
                    count=q.size();
                    if(count)ans++;
                    }
            
        
        for(int i=0;i<n;++i){
            for(int j=0;j<m;++j){
                if(grid[i][j]==1) return -1;
            }
        }
        return ans;
    }
};
