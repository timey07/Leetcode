class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        queue<pair<int,int>> q;
        int count=0;
        for(int i=0;i<m;++i){
            for(int j=0;j<n;++j){
                if(grid[i][j]==2){
                    q.push({i,j});
                }
                else if(grid[i][j]==1) count++;
            }
        }
        if(count==0) return 0;
        if(q.empty()) return -1;
        int ans=0;
        while(!q.empty()){
            int k=q.size();
            while(k--){
                int x=q.front().first;
                int y=q.front().second;
                q.pop();
                int dx[]={0,1,0,-1};
                int dy[]={1,0,-1,0};
                for(int i=0;i<4;++i){
                    int a=x+dx[i];
                    int b=y+dy[i];
                    if(a>=0 && b>=0 && a<m && b<n && grid[a][b]==1){
                        count--;
                        grid[a][b]=2;
                        q.push({a,b});
                    }
                }
            }
            if(!q.empty()) ans++;
        }

        if(count) return -1;
        else return ans;
    }
};
