class Solution {
public:
    int climbStairs(int n) {
        int m=n/2;
        long long ans=0;
        for(int twos=0;twos<=m;++twos){
            int ones=n-(2*twos);
            int total=ones+twos;
            long long ncr=1;
            for(int j=0;j<min(ones,twos);++j){
                ncr= ncr*(total-j)/(j+1);
            }
            ans+=ncr;
        }
        return ans;
    }
};
