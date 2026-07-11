class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int sum=0;
        int ans=0;
        int n=nums.size();
        for(int i=0;i<n;++i){
            if(nums[i]==1) sum++;
            else sum=0;
            ans=max(sum,ans);
        }
        return ans;
    }
};
