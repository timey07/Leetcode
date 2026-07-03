class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n=nums.size();
        vector<int> ans(nums.begin(),nums.end());
        for(int i=1;i<n;++i){
            ans[i]*=ans[i-1];
        }
        int c=1;
        for(int i=n-1;i>=1;--i){
            ans[i]=ans[i-1]*c;
            c*=nums[i];
        }
        ans[0]=c;
        return ans;
    }
};
