class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        int maxi=0;int n=nums.size();
        vector<int> gcd(n);
        
        for(int i=0;i<n;++i){
            maxi=max(nums[i],maxi);
            gcd[i]=__gcd(nums[i],maxi);
        }
        sort(gcd.begin(),gcd.end());
        long long ans=0;
        for(int i=0;i<(n/2);++i){
            ans+= __gcd(gcd[i],gcd[n-i-1]);
        }
        return ans;
    }
};
