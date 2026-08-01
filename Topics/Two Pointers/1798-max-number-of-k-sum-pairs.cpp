class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int ans=0;
        int low=0;
        int high=nums.size()-1;
        while(low<high){
            int sum=nums[low]+nums[high];
            if(sum==k){
                ans++;
                low++;
                high--;
            }
            else if(sum>k)high--;
            else low++;
        }
        return ans;
    }
};
