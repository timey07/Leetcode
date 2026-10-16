class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n=nums.size();
        if(n==1) return nums[0];
        int low=0;
        int high=n-1;
        while(low<=high){
            int mid=(low+high)/2;
            if(mid%2){
                if(nums[mid]==nums[mid-1]) low=mid+1;
                else if(mid==n-1 || nums[mid]!=nums[mid+1]) return nums[mid];
                else high=mid-1;
            }
            else{
                if(mid<n-1 && nums[mid]==nums[mid+1]) low=mid+1;
                else if(mid<n-1 && nums[mid]!=nums[mid+1]){
                    if(mid==0 || nums[mid]!=nums[mid-1]) return nums[mid];
                    else high=mid-1;
                }
                else if(mid==n-1 && nums[mid]!=nums[mid-1]) return nums[mid];
                else high=mid-1;
            }
        }
        return -1;
    }
};
