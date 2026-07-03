class Solution {
public:
    bool search(vector<int>& nums, int target) {
          int low=0,high=nums.size()-1;
        while(low<=high){
            int mid=(low+high)/2;
            if(nums[mid]==target) return true;
          
            if(nums[low]==nums[high] && nums[low]==nums[mid]){
                low++;
                high--;
                continue;
            }
              // left
            if(nums[mid]>=nums[low]){
              
                if(nums[mid]>target && nums[low]<=target)  high=mid-1;
                else low=mid+1;
            }
            // right
            else{
                if(nums[mid]<target && nums[high]>=target) low=mid+1;
                else high=mid-1;
            }
        }
        return false;
    }
};
