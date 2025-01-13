class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int low=1;
        int high=*max_element(nums.begin(),nums.end());
        int ans=high;
        while(low<=high){
            int mid=(low+high)/2;
           long long sum=0;
            for(int i=0;i<nums.size();++i){
                sum+=(nums[i]+mid-1)/mid;
                if(sum>threshold) break;
            }
            if(sum<=threshold){
                high=mid-1;
                ans=mid;
            }
            else low=mid+1;
        }
        return ans;
    }
};
