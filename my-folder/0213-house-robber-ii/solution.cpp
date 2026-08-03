class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==1) return nums[0];
        int prev2=nums[0];
        int prev1=nums[1];
        int prev3=INT_MIN;
        for(int i=2;i<n-1;++i){
            int curr=nums[i]+max(prev2,prev3);
            prev3=prev2;
            prev2=prev1;
            prev1=curr;
        }
        int ans=max(prev1,prev2);
        if(n==2) return ans;
        prev2=nums[1];
        prev1=nums[2];
        prev3=INT_MIN;
        for(int i=3;i<n;++i){
            int curr=nums[i]+max(prev2,prev3);
            prev3=prev2;
            prev2=prev1;
            prev1=curr;
        }
        ans=max(ans,max(prev1,prev2));
        return ans;
    }
};
