class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n=nums.size();
        int total= accumulate(nums.begin(),nums.end(),0);
        if(abs(target-total)%2) return 0;
        if(abs(target)>total) return 0;
        int sum=(abs(target-total))/2;
        // vector<vector<int>> dp(n,vector<int>(sum+1,0));
        vector<int> prev(sum+1,0);

        prev[0]=1;
        if(nums[0]==0) prev[0]=2;
        else if(nums[0]<=sum) prev[nums[0]]=1;
        // for(int i=0;i<n;++i) dp[i][sum]=1;
        for(int i=1;i<n;++i){
            vector<int> curr(sum+1,0);
            curr[0]=1;
            for(int j=0;j<=sum;++j){
                int notTake= prev[j];
                int take=0;
                if(nums[i]<=j) take=prev[j-nums[i]];
                curr[j]=notTake+take;
            }
            prev=curr;
        }
        return prev[sum];
    }
};
