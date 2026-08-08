class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n=nums.size();
        if(n==1) return nums[0];
        vector<int> dp1(n);
        vector<int> dp2(n);
        dp1[0]=nums[0];
        dp2[0]=nums[0];
        int ans=nums[0];
        for(int i=1;i<n;++i){
            dp1[i]=max(nums[i],max(nums[i]*dp1[i-1],nums[i]*dp2[i-1]));
            dp2[i]=min(nums[i],min(nums[i]*dp1[i-1],nums[i]*dp2[i-1]));
            ans=max(ans,dp1[i]);
        }
        return ans;
    }
};
