class Solution {
    int solve(vector<int>&coins,int in,int amount,vector<vector<int>>&dp){
        if(amount==0) return dp[in][amount]=1;
        if(in==0){
            if(amount%coins[in]==0) return dp[in][amount]=1;
            else return 0;
        }
        if(dp[in][amount]!=-1) return dp[in][amount];
        int take=0;
        if(coins[in]<=amount) take= solve(coins,in,amount-coins[in],dp);
        int notTake= solve(coins,in-1,amount,dp);
        return dp[in][amount]=(take+notTake);
    }
public:
    int change(int amount, vector<int>& coins) {
        int n=coins.size();
        sort(coins.begin(),coins.end());
        vector<vector<int>>dp(n,vector<int>(amount+1,-1));
        solve(coins,n-1,amount,dp);
        if(dp[n-1][amount]==-1) return 0;
        return dp[n-1][amount];
    }
};
