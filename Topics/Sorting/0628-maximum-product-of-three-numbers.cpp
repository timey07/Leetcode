class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        int n=nums.size();
        int max1=INT_MIN;
        int max2=INT_MIN;
        int max3=INT_MIN;
        int mini1=INT_MAX;
        int mini2=INT_MAX;
        for(int i=0;i<n;++i){
            int el=nums[i];
            if(el>=max1){
                max3=max2;
                max2=max1;
                max1=el;
            }
            else if(el>=max2){
                max3=max2;
                max2=el;
            }
            else if(el>=max3) max3=el;

            if(el<=mini1){
                mini2=mini1;
                mini1=el;
            }
            else if(el<=mini2) mini2=el;
        }
        int ans= max(max1*max2*max3,mini1*mini2*max1);
        return ans;
    }
};
