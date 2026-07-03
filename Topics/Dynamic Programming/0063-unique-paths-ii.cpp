class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>> ans(n,vector<int>(m,0));

        for(int i=0;i<n;++i){
            for(int j=0;j<m;++j){
                if(grid[i][j]) continue;
                if(i==0 && j==0) ans[i][j]=1;
                else{
                    int up=0,left=0;
                    if(i) up=ans[i-1][j];
                    if(j) left=ans[i][j-1];
                    ans[i][j]=up+left;
                }
            }
        }
        return ans[n-1][m-1];
    }
};
