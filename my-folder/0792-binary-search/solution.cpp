class Solution {
public:
    int search(vector<int>& nums, int target) {
        int low=0;
        int high=nums.size()-1;
        int mid=(high+low)/2;
        while(nums[mid]!=target && mid<high){
            if(nums[mid]>target){
                high=mid-1;
            }
            else low=mid+1;
            mid=(low+high)/2;
        }
        if(nums[mid]==target) return mid;
        else return -1;
    }
};
