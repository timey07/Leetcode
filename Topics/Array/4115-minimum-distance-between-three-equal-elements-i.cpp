class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        int n=nums.size();
        vector<queue<int>> v(n+1);
        int ans=INT_MAX;
        for(int i=0;i<n;++i){
            v[nums[i]].push(i);
            if(v[nums[i]].size()==3){
                int first=v[nums[i]].front();
                v[nums[i]].pop();
                ans=min(ans,2*(i-first));
            }
        }
        if(ans==INT_MAX) return -1;
        return ans;
    }
};
