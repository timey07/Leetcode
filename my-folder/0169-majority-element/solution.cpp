class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count=0;
        int n=nums.size();
        int curr=nums[0];
        for(int i=0;i<n;++i){
            if(count==0) curr=nums[i];

            if(nums[i]!=curr) count--;
            else count++;
        }
        return curr;
    }
};
