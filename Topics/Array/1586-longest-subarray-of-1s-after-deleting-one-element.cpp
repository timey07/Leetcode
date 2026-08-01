class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int ans=0;
        int low=0;
        int zeros=0;
        int n=nums.size();
        for(int i=0;i<n;++i){
            if(nums[i]==0 && zeros<=1) zeros++;
            while(zeros>1){
                if(nums[low]==0) zeros--;
                low++;
            }
            ans=max(ans,i-low);
        }
        return ans;
    }
};
