class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int ans1=-1,ans2=-1;
        int low=0;
        int high=nums.size()-1;
        while(low<=high){
            int mid= (high+low)/2;
            if(nums[mid]>=target){
                ans2=mid;
                high=mid-1;
            }
            else low=mid+1;
        }
         low=0;
        high=nums.size()-1;
        while(low<=high){
            int mid= (high+low)/2;
            if(nums[mid]<=target){
                ans1=mid;
                low=mid+1;
            }
            else high=mid-1;
        }
        if( ans1!=-1 && nums[ans1]==target){
            return {ans2,ans1};}

           else{ ans1=-1;
            ans2=-1;
            return {ans1,ans2};}
    }
};
