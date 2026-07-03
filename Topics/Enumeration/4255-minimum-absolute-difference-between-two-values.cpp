class Solution {
public:
    int minAbsoluteDifference(vector<int>& nums) {
        int n=nums.size();
        int ans=INT_MAX;
        for(int i=0;i<n-1;++i){
            if(nums[i]==0) continue;
            for(int j=i+1;j<n;++j){
                if(nums[i]==1 && nums[j]==2){
                    ans=min(ans,j-i);
                    break;
                }
                if(nums[i]==2 && nums[j]==1){
                    ans=min(ans,j-i);
                    break;
                }
            }
        }
        if(ans==INT_MAX) return -1;
        else return ans;
        }
};
