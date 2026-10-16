class Solution {
public:
    bool search(vector<int>& nums, int target) {
        if(nums[0]==target) return true;
        int low=0;
        int high=nums.size()-1;
        while(low<high){
            int mid=(low+high)/2;
            if(nums[mid]==target) return true;
            if(nums[high]==target) return true;
            if(nums[low]==target) return true;
            if(nums[low]==nums[high] && nums[mid]==nums[low]){
                 low++;
                 high--;
                 continue;
            }
            if(target<nums[mid] && target>nums[low]) high=mid-1;
            if(target<nums[mid] && target<nums[low]){
                if(nums[mid]<nums[low]) high=mid-1;
                else low=mid+1;
            }
            if(target>nums[mid] && target<nums[high]) low=mid+1;
            if(target>nums[mid] && target>nums[high]){
                if(nums[low]>nums[mid]) high=mid-1;
                else low=mid+1;
            }
        }
        return false;;
    }
};
