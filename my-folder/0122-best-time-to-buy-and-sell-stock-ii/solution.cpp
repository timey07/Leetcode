class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        // vector<vector<int>> dp(n+1,vector<int>(2,0));
        // vector<int> curr(2,0);
        // vector<int> next(2,0);
        // for(int i=n-1;i>=0;--i){
        //     int notTake= next[1];
        //     int take= -prices[i]+next[0];
        //     curr[1]=max(take,notTake);

        //     notTake= next[0];
        //     take= prices[i]+next[1];
        //     curr[0]=max(take,notTake);

        //     next=curr;
        // }
        // return next[1];

        int mini=INT_MAX;
        int ans=0;
        for(int i=0;i<n;++i){
            if(prices[i]>mini){
                ans+=(prices[i]-mini);
                mini=prices[i];
            }
            mini=min(mini,prices[i]);
        }
        return ans;
    }
};
