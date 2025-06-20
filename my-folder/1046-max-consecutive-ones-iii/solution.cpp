class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int z=0;
         int l=0;
         int r=0;
         int ans=0;
         while(r<nums.size()){
            if(nums[r]==0 && z<k){
                z++;
                ans=max(ans,r-l+1);
                r++;
                continue;
            }
            if(nums[r]==0){
                z++;
                if(k==0){
                    l=r+1;
                    z--;
                    r++;
                    continue;
                }
                while(z>k){
                    if(nums[l]==0) z--;
                    l++;
                }
            }
            ans=max(ans,(r-l+1));
            r++;
         }
         return ans;
    }
};
