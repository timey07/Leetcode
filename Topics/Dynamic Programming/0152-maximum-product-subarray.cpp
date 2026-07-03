class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n=nums.size();
        int mini=1;
        int maxi=1;
        int ans=INT_MIN;
        for(int i=0;i<n;++i){
            int temp=maxi;
            maxi=max(nums[i],max(nums[i]*maxi,nums[i]*mini));
            mini=min(nums[i],min(nums[i]*temp,nums[i]*mini));
            ans=max(ans,max(mini,maxi));
        }
        return ans;
    }
};
