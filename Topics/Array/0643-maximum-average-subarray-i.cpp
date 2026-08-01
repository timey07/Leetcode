class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int n=nums.size();
        double ans=INT_MIN;
        int sum=0;
        int low=0;
        for(int i=0;i<n;++i){
            sum+=nums[i];
            if(i-low+1==k){
                ans=max(ans,double(sum)/k);
                sum-=nums[low];
                low++;
            }
        }
        return ans;
    }
};
