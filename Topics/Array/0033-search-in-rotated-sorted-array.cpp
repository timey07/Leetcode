class Solution {
public:
    int search(vector<int>& nums, int target) {
        if(nums[0]==target) return 0;
        int low=0;
        int high=nums.size()-1;
        while(low<high){
            int mid=(low+high)/2;
            if(nums[mid]==target) return mid;
            if(nums[high]==target) return high;
            if(nums[low]==target) return low;
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
        return -1;
    }
};
