class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        int sum=0;
        int ans=0;
        int n=nums.size();
        for(int i=0;i<n;++i){
            sum+=nums[i];
            if(sum==k) ans++;
            if(mp[sum-k]) ans+=mp[sum-k];
             mp[sum]++;
        }
        return ans;
    }
};
