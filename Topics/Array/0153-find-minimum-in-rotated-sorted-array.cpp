class Solution {
public:
    int findMin(vector<int>& nums) {
        int n=nums.size();
        int high=n-1;
        int low=0;
        int mid;
        while(low<=high){
            mid=(low+high)/2;
            if(nums[mid]>nums[high]) low=mid+1;
            else if(nums[mid]<nums[low]){
                high=mid;
                low++;
            }
            else high=mid-1;
        }
        return nums[mid];
    }
};
