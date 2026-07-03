class Solution {
    public:
    int mod=1e9+7;
    int dp[301][301];
public:
int solve(int n,int i,int x){
    if(n==0) return 1;

    int val=pow(i,x);
    if(val>n) return 0;

    if(dp[n][i]!=-1) return dp[n][i];
    int take=solve(n-val,i+1,x);
    int ntake=solve(n,i+1,x);

    return dp[n][i]=(take+ntake)%mod;
}
public:
    int numberOfWays(int n, int x) {
        memset(dp,-1,sizeof(dp));
        return solve(n,1,x);
    }
};
