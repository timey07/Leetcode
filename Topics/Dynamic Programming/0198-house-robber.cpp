class Solution {
    private:
    int solve(int i,vector<int>&nums,vector<int>&dp){
        if(i<=1) return dp[i]=nums[i];
        if(i==2) return dp[i]=nums[i]+nums[i-2];
        if(dp[i]!=-1) return dp[i];
        int one= solve(i-2,nums,dp);
        int two= solve(i-3,nums,dp);
        return dp[i]= nums[i]+max(one,two);
    }
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==1) return nums[0];
        // vector<int> dp(n,-1);
        // solve(n-1,nums,dp);
        // solve(n-2,nums,dp);

        int prev2=nums[0];
        int prev=nums[1];
        int prev3=INT_MIN;

        for(int i=2;i<n;++i){
            int sum=nums[i]+max(prev2,prev3);
            prev3=prev2;
            prev2=prev;
            prev=sum;
        }
        return max(prev,prev2);
    }
};
