class Solution {
public:
    void solve(vector<int> &nums, int target, vector<vector<int>> &ans, vector<int> &ds, int start) {
        if (target == 0) {
            ans.push_back(ds);
            return;
        }

        for (int i = start; i < nums.size(); i++) {
            if (i > start && nums[i] == nums[i-1]) continue; 
            if (nums[i] > target) break;

            ds.push_back(nums[i]);
            solve(nums, target - nums[i], ans, ds, i + 1);
            ds.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> ans;
        vector<int> ds;
        solve(candidates, target, ans, ds, 0);
        return ans;
    }
};

