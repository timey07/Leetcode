class Solution {
public:
    int getMinDistance(vector<int>& nums, int target, int start) {
        int n=nums.size();
        int check=0,store=-1;
        int ans=n+1;
        for(int i=0;i<n;++i){
            if(nums[i]==target && !check) store=i;
            if(i==start){
                check=1;
                if(store!=-1) ans=i-store;
                store=i;
            }
            if(nums[i]==target && check){
                ans=min(ans,i-store);
                break;
            }
        }
        return ans;
    }
};
