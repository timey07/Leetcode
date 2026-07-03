class Solution {
public:
    int jump(vector<int>& nums) {
        int n=nums.size();
        if(n==1) return 0;
        int ans=0;
        int i=0;
        while(i<n){
            ans++;
            int ind=i;
            if(i+nums[i]>=(n-1)) break;
            int maxi=0;
            for(int j=1;j<=nums[i];++j){
                if(nums[i+j]+(i+j)>=maxi){
                    ind=i+j;
                    maxi=nums[ind]+ind;
                }
            }
            i=ind;
        }
        return ans;
    }
};
