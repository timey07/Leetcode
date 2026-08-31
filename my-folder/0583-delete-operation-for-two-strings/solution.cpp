class Solution {
    private:
    int solve(int i,int j,string &s,string &t,vector<vector<int>>&dp){
        if(i<0 || j<0) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        if(s[i]==t[j]) return dp[i][j]=1+solve(i-1,j-1,s,t,dp);
        dp[i][j]=max(solve(i-1,j,s,t,dp),solve(i,j-1,s,t,dp));
        return dp[i][j];
    }
public:
    int minDistance(string word1, string word2) {
        int n=word1.size();
        int m=word2.size();
        // vector<vector<int>> dp(n,vector<int>(m,-1));
        // int val=solve(n-1,m-1,word1,word2,dp);
        vector<int>prev(m+1,0);
        for(int i=1;i<=n;++i){
            vector<int> curr(m+1,0);
            for(int j=1;j<=m;++j){
                if(word1[i-1]==word2[j-1]) curr[j]=1+prev[j-1];
                else curr[j]=max(curr[j-1],prev[j]);
            }
            prev=curr;
        }
        int ans=n+m-2*prev[m];
        return ans;
    }
};
