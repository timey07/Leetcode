class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int ans1= lower_bound(nums.begin(),nums.end(),target)-nums.begin();
        if(ans1==nums.size() || nums[ans1]!=target) return {-1,-1};
        int ans2= upper_bound(nums.begin(),nums.end(),target)-nums.begin()-1;
        return {ans1,ans2};
    }
};
