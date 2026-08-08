class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        // if(grid[0][0]) return 0;
        int n=grid.size();
        int m=grid[0].size();
        // vector<vector<int>> dp(n,vector<int>(m,0));
        vector<int> prev(m,0);
        // for(int i=0;i<n;++i){ 
        //     if(grid[i][0]) break;
        //     dp[i][0]=1;
        //     }
        for(int i=0;i<m;++i){
            if(grid[0][i]) break;
            prev[i]=1;
        }
        for(int i=1;i<n;++i){
            vector<int> curr(m,0);
            if(!grid[i][0]) curr[0]=prev[0];
            for(int j=1;j<m;++j){
                if(grid[i][j])continue;
                curr[j]=prev[j]+curr[j-1];
            }
            prev=curr;
        }
        return prev[m-1];
    }
};
