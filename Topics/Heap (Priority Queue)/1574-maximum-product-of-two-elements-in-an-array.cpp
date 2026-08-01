class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxi1=0;
        int maxi2=0;
        int n=nums.size();
        for(int i=0;i<n;++i){
            if(nums[i]>=maxi1){
                maxi2=maxi1;
                maxi1=nums[i];
            }
            else if(nums[i]>maxi2) maxi2=nums[i];
        }
        int ans=(maxi1-1)*(maxi2-1);
        return ans;
    }
};
