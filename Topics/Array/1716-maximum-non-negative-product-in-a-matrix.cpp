class Solution {
    private:
    long long mod=1e9+7;
public:
    int maxProductPath(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();

        vector<vector<long long>> maxi(m,vector<long long>(n));
        vector<vector<long long>> mini(m,vector<long long>(n));
        maxi[0][0]=mini[0][0]=grid[0][0];
        for(int i=1;i<m;++i){
            maxi[i][0]=mini[i][0]=maxi[i-1][0]*grid[i][0];
        }
        for(int i=1;i<n;++i){
            maxi[0][i]=mini[0][i]=maxi[0][i-1]*grid[0][i];
        }

        for(int i=1;i<m;++i){
            for(int j=1;j<n;++j){
                long long a=maxi[i][j-1]*grid[i][j];
                long long b=maxi[i-1][j]*grid[i][j];
                long long c=mini[i][j-1]*grid[i][j];
                long long d=mini[i-1][j]*grid[i][j];

                maxi[i][j]=max(max(a,b),max(c,d));
                mini[i][j]=min(min(a,b),min(c,d));
            }
        }
        long long ans= maxi[m-1][n-1];
        if(ans<0) return -1;
        else return ans%mod;
    }
};
