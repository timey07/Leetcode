class Solution {
public:
    int countDigitOccurrences(vector<int>& nums, int digit) {
        int n=nums.size();
        int ans=0;
        for(int i=0;i<n;++i){
            int temp=nums[i];
            while(temp){
                int rem=temp%10;
                if(rem==digit) ans++;
                temp/=10;
            }
        }
        return ans;
    }
};
