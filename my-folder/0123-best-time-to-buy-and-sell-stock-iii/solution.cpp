class Solution {
    private:
    int solve(int i,int n,vector<int>&prices,vector<vector<vector<int>>>&dp,int buy,int cap){
        if(cap==0) return 0;
        if(i==n) return 0;
        if(dp[i][buy][cap]!=-1) return dp[i][buy][cap];
        
        if(buy){
            int notTake= solve(i+1,n,prices,dp,1,cap);
            int take= -prices[i]+solve(i+1,n,prices,dp,0,cap);
            dp[i][buy][cap]=max(notTake,take);
        }
        else{
            int notTake= solve(i+1,n,prices,dp,0,cap);
            int take= prices[i]+solve(i+1,n,prices,dp,1,cap-1);
            dp[i][buy][cap]=max(notTake,take);
        }
        return dp[i][buy][cap];
    }
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        // vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(2,vector<int>(3,0)));
        // return solve(0,n,prices,dp,1,2);
        vector<vector<int>> curr(2,vector<int>(3,0));
        vector<vector<int>> next(2,vector<int>(3,0));
        for(int i=n-1;i>=0;--i){
            for(int j=0;j<2;++j){
                for(int cap=1;cap<=2;++cap){
                    if(j){
                        int notTake= next[1][cap];
                        int take= -prices[i]+next[0][cap];
                        curr[j][cap]=max(notTake,take);
                    }
                    else{
                        int notTake= next[0][cap];
                        int take=prices[i]+next[1][cap-1];
                        curr[j][cap]=max(notTake,take);
                    }
                }
            }
            next=curr;
        }
        return next[1][2];
    }
};
