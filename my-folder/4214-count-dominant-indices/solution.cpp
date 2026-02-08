class Solution {
public:
    int dominantIndices(vector<int>& nums) {
        int n=nums.size();
        double avg[n];
        int sum=0;
        for(int i=n-1;i>=1;--i){
            sum+=nums[i];
            avg[i]=sum/(n-i);
        }
        int ans=0;
        for(int i=0;i<n-1;++i){
            if(nums[i]>avg[i+1]) ans++;
        }
        return ans;
    }
};
