class Solution {
    private:
    int solve(vector<int>&nums,vector<int>&dp,int in){
        if(in==0) return 1;
        if(dp[in]) return dp[in];

        dp[in]=1;
        for(int i=0;i<in;++i){
            if(nums[i]<nums[in]){
                dp[in]=max(dp[in],solve(nums,dp,i)+1);
            }
        }
        return dp[in];
    }

public:
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp;
        
        int len=0;
        dp.push_back(nums[0]);
        for(int i=1;i<n;++i){
            if(dp[len]<nums[i]){
                dp.push_back(nums[i]);
                len++;
                continue;
            }
            int in = lower_bound(dp.begin(),dp.end(),nums[i])-dp.begin();
            dp[in]=nums[i];
        }
        return len+1;
    }
};
