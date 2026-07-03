class Solution {
public:
    int splitArray(vector<int>& nums, int k) {
        int n=nums.size();
        int low=*max_element(nums.begin(),nums.end());
        int high=accumulate(nums.begin(),nums.end(),0);
        int ans=high;
        while(low<=high){
            int mid=(low+high)/2;
            int parts=1;
            int sum=0;
            for(int i=0;i<n;++i){
                if(sum+nums[i]>mid){
                    parts++;
                    sum=0;
                }
                if(parts>k) break;
                sum+=nums[i];
            }
            if(parts<=k){
                ans=mid;
                high=mid-1;
            }
            else low=mid+1;
        }
        return ans;
    }
};
