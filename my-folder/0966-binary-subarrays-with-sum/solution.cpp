class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int ans=0;
        int sum=0;
        int l=0;
        int r=0;
        while(r<nums.size()){
            sum+=nums[r];
            while(sum>goal){
                sum-=nums[l];
                l++;
            }
            ans+=(r-l+1);
            r++;
        }
        l=0,r=0;
        sum=0;
        goal--;
        while(r<nums.size()){
            if(goal<0) break;
            sum+=nums[r];
            while(sum>goal){
                sum-=nums[l];
                l++;
            }
            ans-=(r-l+1);
            r++;
        }
        return ans;
    }
};
