class Solution {
public:
    int minimumDifference(vector<int>& nums) {
        int n=nums.size()/2;
        int total = accumulate(nums.begin(), nums.end(), 0);
        vector<vector<int>> left(n+1);
        vector<vector<int>> right(n+1);
        for(int mask=0;mask<(1<<n);++mask){
            int lsum=0;
            int rsum=0;
            int bits = __builtin_popcount(mask);
            for(int i=0;i<n;++i){
                if(mask&(1<<i)){
                    lsum+=nums[i];
                    rsum+=nums[i+n];
                }
            }
            left[bits].push_back(lsum);
            right[bits].push_back(rsum);
        }

        for(int i=0;i<=n;++i) sort(right[i].begin(),right[i].end());

        int ans=INT_MAX;
        for(int k=0;k<=n;++k){
            for(auto lsum:left[k]){
                int need= total/2 -lsum;
            int in= lower_bound(right[n-k].begin(),right[n-k].end(),need)-right[n-k].begin();

            if(in!=right[n-k].size()){
                int sum= lsum + right[n-k][in];
                ans=min(ans,abs(total-2*sum));
            }
            if(in!=0){
                in--;
                int sum=lsum+right[n-k][in];
                ans=min(ans,abs(total-2*sum));
            }
            }
        }
        return ans;
    }
};
