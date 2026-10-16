class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n=prices.size();
        vector<int> curr(2,0);
        vector<int> next(2,0);
        for(int i=n-1;i>=0;--i){
            
            int notTake= next[1];
            int take= -prices[i]+next[0];
            curr[1]=max(notTake,take);
        
            notTake= next[0];
            take= prices[i]+next[1]-fee;
            curr[0]=max(notTake,take);
            
            next=curr;
        }
        return next[1];
    }
};
