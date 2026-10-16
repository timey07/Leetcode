class Solution {
public:
    int search(vector<int>& nums, int target) {
        int ans= lower_bound(nums.begin(),nums.end(),target)-nums.begin();
        if(ans==nums.size()) return -1;
        if(nums[ans]!=target) return -1;
        return ans;
    }
};
