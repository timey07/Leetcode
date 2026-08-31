class Solution {
    private:
    int solve(vector<vector<int>>&dp,int i,int j,string s,string t){
        if(i<0) return j+1;
        if(j<0) return i+1;

        if(dp[i][j]!=-1) return dp[i][j];
        if(s[i]==t[j]) dp[i][j]=solve(dp,i-1,j-1,s,t);
        else{
            dp[i][j]=1+min(solve(dp,i-1,j,s,t),min(solve(dp,i,j-1,s,t),solve(dp,i-1,j-1,s,t)));
        }
        return dp[i][j];
    }
public:
    int minDistance(string s, string t) {
        int n=s.size();
        int m=t.size();

        // vector<vector<int>> dp(n+1,vector<int>(m+1,0));
        // return solve(dp,n-1,m-1,s,t);
        vector<int> prev(m+1,0);
        for(int i=0;i<=m;++i) prev[i]=i;

        for(int i=1;i<=n;++i){
            vector<int>curr(m+1,0);
            curr[0]=i;
            for(int j=1;j<=m;++j){
                if(s[i-1]==t[j-1]) curr[j]=prev[j-1];
                else{
                    curr[j]=1+min(prev[j-1],min(prev[j],curr[j-1]));
                }
            }
            prev=curr;
        }
        return prev[m];
    }
};
