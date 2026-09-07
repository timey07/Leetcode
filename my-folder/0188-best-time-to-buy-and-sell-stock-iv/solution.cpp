class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n=prices.size();
        vector<int> curr(2*k+1,0);
        vector<int> next(2*k+1,0);
        for(int i=n-1;i>=0;--i){
                for(int cap=2*k-1;cap>=0;--cap){
                    if(cap%2==0){
                        int notTake= next[cap];
                        int take= -prices[i]+next[cap+1];
                        curr[cap]=max(notTake,take);
                    }
                    else{
                        int notTake= next[cap];
                        int take=prices[i]+next[cap+1];
                        curr[cap]=max(notTake,take);
                    }
                }
            
            next=curr;
        }
        return next[0];
    }
};
