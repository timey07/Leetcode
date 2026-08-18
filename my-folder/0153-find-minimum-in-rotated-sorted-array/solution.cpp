class Solution {
public:
    int findMin(vector<int>& nums) {
        // int target=INT_MIN;
        int low=0;
        int high=nums.size()-1;
        int ans=INT_MAX;
        while(low<=high){
            int mid=(low+high)/2;
            ans=min(ans,nums[mid]);
            if(nums[mid]<=nums[high]) high=mid-1;
            else if(nums[mid]>nums[high]) low=mid+1;
        }
        return ans;
    }
};
