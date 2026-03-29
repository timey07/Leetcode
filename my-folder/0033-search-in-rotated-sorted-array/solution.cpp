class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n=nums.size();
        int low=0;
        int high=n-1;
        while(low<=high){
            int mid=(low+high)/2;
            if(target==nums[mid]) return mid;
            if(target>nums[mid]){
                if(target<=nums[high]) low=mid+1;
                else{
                    if(nums[mid]>=nums[low]) low=mid+1;
                    else high=mid-1;
                }
            }
            else{
                if(target>=nums[low]) high=mid-1;
                else{
                    if(nums[mid]>=nums[low]) low=mid+1;
                    else high=mid-1;
                }
            }
        }
        return -1;
    }
};
