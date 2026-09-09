class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        // vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(2,vector<int>(3,0)));
        vector<vector<int>> curr(2,vector<int>(3,0));
        vector<vector<int>> next(2,vector<int>(3,0));
        for(int i=n-1;i>=0;--i){
            for(int cap=1;cap<=2;++cap){
                
                int notTake= next[1][cap];
                int take= -prices[i]+next[0][cap];
                curr[1][cap]=max(take,notTake);
            
                notTake= next[0][cap];
                take= prices[i]+next[1][cap-1];
                curr[0][cap]=max(take,notTake);

                next[0][cap]=curr[0][cap];
                next[1][cap-1]=curr[1][cap-1];
            }
            next[1][2]=curr[1][2];
        }
        return next[1][2];
    }
};
