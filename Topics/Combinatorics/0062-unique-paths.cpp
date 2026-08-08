class Solution {
    private:
    int solve(int m,int n,vector<vector<int>>&dp){
        if(m==0 || n==0) return dp[m][n]=1;
        if(dp[m][n]) return dp[m][n];
        int up=solve(m-1,n,dp);
        int left=solve(m,n-1,dp);
        return dp[m][n]=up+left;
    }
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m,vector<int>(n,0));
        solve(m-1,n-1,dp);
        return dp[m-1][n-1];

        // vector<int> prev(n,1);
        
        // for(int i=1;i<m;++i){
        //     vector<int> curr(n,1);
        //     for(int j=1;j<n;++j){
        //         curr[j]=prev[j]+curr[j-1];
        //     }
        //     prev=curr;
        // }
        // return prev[n-1];
    }
};
