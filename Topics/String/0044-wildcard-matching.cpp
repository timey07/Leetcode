class Solution {
    private:
    int solve(int i,int j,string s,string t,vector<vector<int>>&dp){
        if(i<0 && j<0) return 1;
        if(j<0) return 0;
        if(i<0){
            while (j>=0){
                if (t[j]!='*') return 0;
                j--;
            }
            return 1;
        }
        if(dp[i][j]!=-1) return dp[i][j];
        if(s[i]==t[j] || t[j]=='?') return dp[i][j]=solve(i-1,j-1,s,t,dp);
        else if(t[j]=='*'){
            int notTake= solve(i-1,j,s,t,dp);
            int take= solve(i,j-1,s,t,dp);
            return dp[i][j]= notTake || take;
        }
        else return dp[i][j]=0;
    }
public:
    bool isMatch(string s, string p) {
        int n=s.size();
        int m=p.size();
        // vector<vector<bool>> dp(n+1,vector<bool>(m+1,false));
        vector<bool> prev(m+1,false);
        vector<bool> curr(m+1,false);
        // return solve(n-1,m-1,s,p,dp);
        prev[0]=true;
        for(int j=1;j<=m;++j){
            if(p[j-1]=='*') prev[j]=true;
            else break;
        }

        for(int i=1;i<=n;++i){
            for(int j=1;j<=m;++j){
                if(s[i-1]==p[j-1] || p[j-1]=='?') curr[j]=prev[j-1];
                else if(p[j-1]=='*'){
                    curr[j]= curr[j-1] || prev[j];
                }
                else curr[j]=0;
            }
            prev=curr;
        }
        return prev[m];
    }
};
