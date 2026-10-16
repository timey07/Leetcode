class Solution {
    private:
    int solve(vector<int>&coins,int in,int amount,vector<vector<int>>&dp){
        if(amount==0) return dp[in][amount]=0;
        if(in==0){
            if(amount%coins[in]==0) return dp[in][amount]=(amount/coins[in]);
            else return 1e9;
        }
        if(dp[in][amount]!=-1) return dp[in][amount];
        int take=INT_MAX;
        if(coins[in]<=amount) take= 1+solve(coins,in,amount-coins[in],dp);
        int notTake= solve(coins,in-1,amount,dp);
        return dp[in][amount]=min(take,notTake);
    }
public:
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        sort(coins.begin(),coins.end());
        // vector<vector<int>>dp(n,vector<int>(amount+1,-1));
        // solve(coins,n-1,amount,dp);
        vector<int>prev(amount+1,-1);
        prev[0]=0;
        for(int i=coins[0];i<=amount;i+=coins[0]) prev[i]=(i/coins[0]);
        for(int i=1;i<n;++i){
            vector<int> curr(amount+1,-1);
            curr[0]=0;
            for(int target=0;target<=amount;++target){
                int notTake= prev[target];
                int take=INT_MAX;
                if(coins[i]<=target && curr[target-coins[i]]!=-1)
                take=1+curr[target-coins[i]];

                if(notTake!=-1) curr[target]=min(notTake,take);
                else if(take!=INT_MAX) curr[target]=take;
            }
            prev=curr;
        }
        return prev[amount];
    }
};
