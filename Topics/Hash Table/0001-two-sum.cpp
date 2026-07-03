class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> mp;
        int n=nums.size();
        for(int i=0;i<n;++i){
            if(mp[target-nums[i]]>0){
                return {i,mp[target-nums[i]]-1};
            }
            mp[target-nums[i]]=-1;
            mp[nums[i]]=i+1;
            
        }
        return {-1,-1};
    }
};
