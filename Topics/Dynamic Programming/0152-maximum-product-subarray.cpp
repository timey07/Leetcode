class Solution {
    private:
    void solve(vector<int>&nums,vector<int>&dp1,vector<int>&dp2,int in){
        if(in==0){
            dp1[0]=nums[0];
            dp2[0]=nums[0];
            return;
        }

        if(dp1[in]!=INT_MIN) return;

        solve(nums,dp1,dp2,in-1);

        dp1[in]=max(nums[in],max(dp1[in-1]*nums[in],dp2[in-1]*nums[in]));
        dp2[in]=min(nums[in],min(dp1[in-1]*nums[in],dp2[in-1]*nums[in]));

        return;
    }
public:
    int maxProduct(vector<int>& nums) {
        int n=nums.size();
        // solve(nums,dp1,dp2,n-1);
        int mini=nums[0];
        int maxi=nums[0];
        int ans=nums[0];
        for(int i=1;i<n;++i){
            int temp=maxi;
            maxi=max(nums[i],max(maxi*nums[i],mini*nums[i]));
            mini=min(nums[i],min(temp*nums[i],mini*nums[i]));
            ans=max(ans,maxi);
        }
        
        return ans;
    }
};
