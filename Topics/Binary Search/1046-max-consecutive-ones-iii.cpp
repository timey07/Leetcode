class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int ans=0,sum=0;
        int zeros=0;
        int n=nums.size();
        int low=0;
        for(int i=0;i<n;++i){
            if(nums[i]==0 && zeros<k) zeros++;
            else{
                if(nums[i]==0) zeros++;
                while(zeros>k){
                    if(nums[low]==0) zeros--;
                    low++;
                }
            }
            ans=max(ans,i-low+1);
        }
        return ans;
    }
};
