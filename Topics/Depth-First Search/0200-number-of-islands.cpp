class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        unordered_set<int> se;
        int ans=0;
        vector<int> x={-1,0,1,0};
        vector<int> y={0,-1,0,1};
        for(int i=0;i<n;++i){
            for(int j=0;j<m;++j){
                if(grid[i][j]=='1' && se.find(i*m+j)==se.end()){
                    ans++;
                    queue<pair<int,int>> s;
                    s.push({i,j});
                    se.insert(i*m+j);
                    while(!s.empty()){
                        auto a=s.front();
                        s.pop();
                        
                        for(int i=0;i<4;++i){
                            int nx=x[i]+a.first;
                            int ny=y[i]+a.second;
                            if(nx>=0 && nx<n && ny>=0 && ny<m && grid[nx][ny]=='1' && se.find(nx*m+ny)==se.end()){
                                se.insert(nx*m+ny);
                                s.push({nx,ny});
                            }
                        }
                    }
                }
            }
        }
        return ans;
    }
};
