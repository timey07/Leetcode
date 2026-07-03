class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
        int x=0;
        for(int i=0;i<nums.size();++i) x=x^nums[i];
        int n=nums.size()-2;
        for(int i=0;i<n;++i) x=x^i;
        int r= (x&(x-1))^x;
        int b1=0,b2=0;
        for(int i=0;i<n+2;++i){
            if(nums[i]&r) b1=b1^nums[i];
            else b2=b2^nums[i];
        }
        for(int i=0;i<n;++i){
            if(i&r) b1=b1^i;
            else b2=b2^i;
        }
        return {b1,b2};
    }
};
