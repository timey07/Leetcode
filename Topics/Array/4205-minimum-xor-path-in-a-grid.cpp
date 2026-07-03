class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<unordered_set<int>>>ans(n,vector<unordered_set<int>>(m));
        
        ans[0][0].insert(grid[0][0]);
        
        for(int i=1;i<m;++i){
            for(auto x:ans[0][i-1]){
                ans[0][i].insert(x^grid[0][i]);
            }
        }
        
        for(int i=1;i<n;++i){
            for(auto x:ans[i-1][0]){
                ans[i][0].insert(x^grid[i][0]);
            }
        }
        
        for(int i=1;i<n;++i){
            for(int j=1;j<m;++j){
                for(auto x:ans[i-1][j]){
                    ans[i][j].insert(x^grid[i][j]);
                }
                for(auto x:ans[i][j-1]){
                    ans[i][j].insert(x^grid[i][j]);
                }
            }
        }
        
        int res=INT_MAX;
        for(auto x:ans[n-1][m-1]){
            res=min(res,x);
        }
        return res;
    }
};
