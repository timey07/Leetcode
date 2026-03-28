class Solution {
    private:
    long long mod=1e9+7;
    vector<long long> fact,invfact;

    long long power(long long a,long long b){
        long long res=1;
        while(b){
            if(b&1) res=(res*a)%mod;
            a=(a*a)%mod;
            b>>=1;
        }
        return res;
    }

    void init(int n){
        fact.resize(n+1);
        invfact.resize(n+1);
        fact[0]=1;
        for(int i=1;i<=n;i++) fact[i]=(fact[i-1]*i)%mod;
        invfact[n]=power(fact[n],mod-2);
        for(int i=n-1;i>=0;i--) invfact[i]=(invfact[i+1]*(i+1))%mod;
    }

    long long cal(int k,int i){
        if(i<0 || i>k) return 0;
        return (((fact[k]*invfact[i])%mod)*invfact[k-i])%mod;
    }

public:
    int countVisiblePeople(int n, int pos, int k) {
        init(n);
        int right=n-1-pos;
        int left=pos;
        long long ans=0;

        for(int i=max(0,k-right); i<=min(k,left); ++i){
            long long temp=(cal(left,i)*cal(right,k-i))%mod;
            ans=(ans + temp)%mod;
        }

        ans=(ans*2)%mod;
        return ans;
    }
};
