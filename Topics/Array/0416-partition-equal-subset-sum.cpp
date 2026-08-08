class Solution {
    private:
    bool solve(int i,vector<int>&nums,int target,vector<vector<int>>&dp){
        if(target==0) return true;
        if(i==0) return nums[0]==target;
        if(dp[i][target]!=-1) return dp[i][target];

        bool notTake= solve(i-1,nums,target,dp);
        bool take=false;
        if(nums[i]<=target) take= solve(i-1,nums,target-nums[i],dp);
        return dp[i][target]= take || notTake;
    }

public:
    bool canPartition(vector<int>& nums) {
        int n=nums.size();
        int target=0;
        for(int i=0;i<n;++i) target+=nums[i];
        if(target%2) return false;
        target/=2;
        // vector<vector<bool>> dp(n,vector<bool>(target+1,false));
        // return solve(n-1,nums,target,dp);
        vector<bool> prev(target+1,false);
        prev[0]=true;
        if(nums[0]<=target) prev[nums[0]]=true;
        for(int i=1;i<n;++i){
            vector<bool> curr(target+1,false);
            curr[0]=true;
            for(int j=1;j<=target;++j){
                bool notTake=  prev[j];
                bool take=false;
                if(nums[i]<=j) take=prev[j-nums[i]];

                curr[j]= notTake || take;
            }
            if(curr[target]) return true;
            prev=curr;
        }
        return prev[target];
    }
};
