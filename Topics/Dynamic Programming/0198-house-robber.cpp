class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(nums.size()==1) return nums[0];
        if(nums.size()==2) return max(nums[0],nums[1]);
        if(nums.size()==3) return max(nums[0]+nums[2],nums[1]);
    
        int prev3=nums[0];
        int prev2=nums[1];
        int prev=nums[2]+nums[0];
        for(int i=3;i<n;++i){
            int curr=nums[i]+max(prev2,prev3);
            prev3=prev2;
            prev2=prev;
            prev=curr;
        }
        return max(prev,prev2);
    }
};
