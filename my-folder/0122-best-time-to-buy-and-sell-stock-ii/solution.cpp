class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        int ans=0;
        int mini=INT_MAX;
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
