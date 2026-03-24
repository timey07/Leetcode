class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();

        vector<int> prev(m,0);

        for(int i=0;i<n;++i){
            vector<int> cur(m,0);
            for(int j=0;j<m;++j){
                if(i==0 && j==0){
                    cur[j]=grid[i][j];
                    continue;
                }

                int left=grid[i][j]+1e9;
                int up=grid[i][j]+1e9;
                if(j) left-=1e9-cur[j-1];
                if(i) up-=1e9-prev[j];

                cur[j]=min(left,up);
            }
            prev=cur;
        }
        return prev[m-1];
    }
};
