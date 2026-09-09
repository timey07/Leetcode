class Solution {
    private:
    int solve(int i,bool buy,vector<int>&prices,vector<vector<int>>&dp){
        if(i==prices.size()) return 0;
        if(dp[i][buy]!=-1) return dp[i][buy];
        if(buy){
            int take= -prices[i]+solve(i+1,false,prices,dp);
            int notTake= solve(i+1,true,prices,dp);
            return dp[i][buy]=max(take,notTake);
        }
        else return dp[i][buy]=max(prices[i],solve(i+1,false,prices,dp));
    }
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        // vector<vector<int>> dp(n+1,vector<int>(2,0));
        vector<int> curr(2,0);
        vector<int> next(2,0);
        // return solve(0,true,prices,dp);
        for(int i=n-1;i>=0;--i){

            int take= -prices[i]+next[0];
            int notTake= next[1];
            curr[1]=max(take,notTake);

            curr[0]=max(prices[i],next[0]);
            next=curr;
        }
        return next[1];
    }
};
