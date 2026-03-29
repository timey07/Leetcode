class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int i=0;
        vector<vector<int>> ans;
        while(i<n-2){
            int j=i+1;
            int k=n-1;
            
            while(j<k){
                int sum=nums[i]+nums[k]+nums[j];
                if(sum>0) k--;
                else if(sum<0)
                    j++;
                else{
                    ans.push_back({nums[i],nums[j],nums[k]});
                    while(k>j && nums[k]==nums[k-1]) k--;
                    k--;
                    while(j<k && nums[j]==nums[j+1]) j++;
                    j++;
                }
            }
            while(i<n-2 && nums[i]==nums[i+1]) i++;
            i++;
        }
        return ans;
    }
};
