class Solution {
    private:
    bool solve(int in,vector<int>&nums,vector<int>&vis){
        if(vis[in]!=-1) return 1;
        for(int i=0;i<in;++i){
            if(i+nums[i]>=in) return vis[i]=solve(i,nums,vis);
        }
        return 0;
    }
public:
    bool canJump(vector<int>& nums) {
        int n=nums.size();
        int mx=0;
        for(int i=0;i<n;++i){
            if(i>mx) return false;
            mx=max(mx,i+nums[i]);
        }
        return true;
    }
};
