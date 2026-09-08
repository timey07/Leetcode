class Solution {
    private:
    int solve(int i,int j,string &s,string &t,vector<vector<int>>&dp){
        if(i<0) return j+1;
        if(j<0) return i+1;
        if(dp[i][j]!=-1) return dp[i][j];
        if(s[i]==t[j]) return dp[i][j]=solve(i-1,j-1,s,t,dp);
        else{
            return dp[i][j]=1+min(solve(i-1,j,s,t,dp),solve(i,j-1,s,t,dp));
        }
    }
public:
    int minDistance(string word1, string word2) {
        int n=word1.size();
        int m=word2.size();
        // vector<vector<int>> dp(n+1,vector<int>(m+1,0));
        vector<int> prev(m+1,0);
        vector<int> curr(m+1,0);
        // for(int i=0;i<=n;++i) dp[i][0]=i;
        for(int i=0;i<=m;++i) prev[i]=i;
        // return solve(n-1,m-1,word1,word2,dp);
        for(int i=1;i<=n;++i){
            curr[0]=i;
            for(int j=1;j<=m;++j){
                if(word1[i-1]==word2[j-1]) curr[j]=prev[j-1];
                else curr[j]=1+min(prev[j],curr[j-1]);
                prev[j-1]=curr[j-1];
            }
            prev[m]=curr[m];
        }
        return prev[m];
    }
};
