class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int total=0;
        int n=nums.size();
        for(int i=0;i<n;++i) total+=nums[i];
        int sum=0;
        for(int i=0;i<n;++i){
            if(total-nums[i]==2*sum) return i;
            sum+=nums[i];
        }
        return -1;
    }
};
