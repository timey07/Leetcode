class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        if(grid[0][0]==1) return -1;
        int n=grid.size();
        if(grid[n-1][n-1]==1) return -1;
        if(n==1) return 1;
        // int m= grid[0].size();
        queue<pair<int,int>> q;
        q.push({0,0});
        int ans=1;
        // vector<vector<int>> vis(n,vector<int>(n,0));
        while(!q.empty()){
            int m=q.size();
            ans++;
            while(m--){
                int i= q.front().first;
                int j=q.front().second;
                q.pop();
                int dx[]={0,1,0,-1,1,-1,1,-1};
                int dy[]={1,0,-1,0,1,-1,-1,1};
                for(int it=0;it<8;++it){
                    int x=dx[it]+i;
                    int y=dy[it]+j;
                    if(x==n-1 && y==n-1) return ans;
                    if(x<n && y<n && x>=0 && y>=0 && grid[x][y]==0){
                        grid[x][y]=1;
                        q.push({x,y});
                    }
                }
            }
        }
        return -1;
    }
};
