class Solution {
public:
    void solve(int i,int target,vector<int>& nums,vector<int>& ds,vector<vector<int>>& ans){
        if (i == nums.size()) {
            if (target == 0) ans.push_back(ds);
            return;
        }

        if (nums[i] <= target) {
            ds.push_back(nums[i]);
            solve(i, target - nums[i], nums, ds, ans);
            ds.pop_back();
        }

        solve(i + 1, target, nums, ds, ans);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> ds;
        solve(0, target, candidates, ds, ans);
        return ans;
    }
};

