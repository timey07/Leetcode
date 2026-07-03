class Solution {
    public:
    long long mod=1e9+7;
    long long findPower(long long x,long long a){
        if(a==0) return 1;
        long long ans=findPower(x,a/2)%mod;
        ans= ans*ans%mod;
        if(a%2!=0) ans= ans*x%mod;
        return ans;
    }
public:
    long long countGoodNumbers(long long n) {
        long long a=(n+1)/2;
        long long b=n/2;
        long long ans= findPower(5,a)*findPower(4,b)%mod;
        return ans;
    }
};
