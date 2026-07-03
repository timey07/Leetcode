class Solution {
    public:
    void solve(vector<int> &ds,vector<vector<int>>& ans,vector<int> &nums,int start){
        ans.push_back(ds);
        for(int i=start;i<nums.size();++i){\
        if (i > start && nums[i] == nums[i - 1]) continue;
            ds.push_back(nums[i]);
            solve(ds,ans,nums,i+1);
            ds.pop_back();
        }
    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        vector<int> ds;
        solve(ds,ans,nums,0);
        return ans;
    }
};
