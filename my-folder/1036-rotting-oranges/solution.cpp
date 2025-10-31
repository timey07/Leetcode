class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int total=0;
        queue<pair<int,int>> q;
        for(int i=0;i<n;++i){
            for(int j=0;j<m;++j){
                if(grid[i][j]) total++;
                if(grid[i][j]==2) q.push({i,j});
            }
        }
        int ans=0,cnt=0;
        while(!q.empty()){
            int k=q.size();
            cnt+=k;
        while(k--){
            int r=q.front().first;
            int c=q.front().second;
            q.pop();
            if(c+1<m && grid[r][c+1]==1){
                grid[r][c+1]=2;
                q.push({r,c+1});
            } 
            if(r+1<n && grid[r+1][c]==1){
                grid[r+1][c]=2;
                q.push({r+1,c});
            } 
            if(c>0 && grid[r][c-1]==1){
                grid[r][c-1]=2;
                q.push({r,c-1});
            } 
            if(r>0 && grid[r-1][c]==1){
                grid[r-1][c]=2;
                q.push({r-1,c});
            } 
        }
        if(!q.empty()) ans++;
        }
        if(cnt==total) return ans;
        else return -1;
    }
};
