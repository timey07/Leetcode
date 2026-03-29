class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        int ans=0;
        int maxi=prices[n-1];
        for(int i=n-2;i>=0;--i){
            ans=max(ans,maxi-prices[i]);
            maxi=max(maxi,prices[i]);
        }
        return ans;
    }
};
