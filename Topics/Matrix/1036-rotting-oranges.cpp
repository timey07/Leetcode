class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        queue<pair<int,int>> q;
        int count=0;
        for(int i=0;i<n;++i){
            for(int j=0;j<m;++j){
                if(grid[i][j]==2) q.push({i,j});
                if(grid[i][j]==1) count++;
            }
        }
        int ans=0;
        while(!q.empty()){
            int len=q.size();
            while(len--){
                auto node=q.front();
                q.pop();
                int dx[]={0,-1,0,1};
                int dy[]={-1,0,1,0};
                for(int i=0;i<4;++i){
                    int nx= dx[i]+node.first;
                    int ny=dy[i]+node.second;

                    if(nx>=0 && ny>=0 && nx<n && ny<m){
                        if(grid[nx][ny]==1){
                            grid[nx][ny]=2;
                            q.push({nx,ny});
                            count--;
                        }
                    }
                }
            }
            if(!q.empty()) ans++;
        }
        if(count==0) return ans;
        return -1;
    }
};
