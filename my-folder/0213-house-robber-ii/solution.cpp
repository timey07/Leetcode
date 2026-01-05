class Solution {
    private:
    int dp(vector<int>& nums,int n,vector<int>& memo,bool check){
        if(n==0){
            if(check) return 0;
            return nums[0];
        }
        if(n==1) return nums[1];
        if(n==2){
            if(check) return nums[2];
            return nums[0]+nums[2];
        }
        if(memo[n]!=-1) return memo[n];

        int first=nums[n]+dp(nums,n-2,memo,check);
        int second=nums[n]+dp(nums,n-3,memo,check);
        memo[n]=max(first,second);
        return memo[n];
    }
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==1) return nums[0];
        vector<int> memo(n,-1);
        int ans=dp(nums,n-1,memo,true);
        vector<int> memo1(n,-1);
        ans=max(ans,dp(nums,n-2,memo1,false));
        if(n>=3) ans=max(ans,dp(nums,n-3,memo1,false));
        return ans;
    }
};
