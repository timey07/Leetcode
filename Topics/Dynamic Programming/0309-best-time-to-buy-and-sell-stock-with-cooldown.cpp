class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<int> curr(2,0);
        vector<int> next(2,0);
        vector<int> next2(2,0);
        for(int i=n-1;i>=0;--i){

            int notTake= next[1];
            int take= -prices[i]+next[0];
            curr[1]=max(notTake,take);
        
            notTake= next[0];
            take= prices[i]+next2[1];
            curr[0]=max(notTake,take);

            next2=next;        
            next=curr;
        }
        return next[1];
    }
};
