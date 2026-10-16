class Solution {
    private:
    int solve(int i,int j,string &s,string &t,vector<vector<int>>&dp){
        if(i<0 || j<0) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        if(s[i]==t[j]) return dp[i][j]=1+solve(i-1,j-1,s,t,dp);
        else return dp[i][j]=max(solve(i-1,j,s,t,dp),solve(i,j-1,s,t,dp));
    }
public:
    int longestCommonSubsequence(string s, string t) {
        int n=s.size();
        int m=t.size();
        // vector<vector<int>> dp(n+1,vector<int>(m+1,0));
        vector<int> prev(m+1,0);
        vector<int> curr(m+1,0);
        // return solve(n-1,m-1,text1,text2,dp);
        for(int i=1;i<=n;++i){
            for(int j=1;j<=m;++j){
                if(s[i-1]==t[j-1]) curr[j]=1+prev[j-1];
                else curr[j]=max(prev[j],curr[j-1]);
                prev[j-1]=curr[j-1];
            }
            prev[m]=curr[m];
        }
        return prev[m];
    }
};
