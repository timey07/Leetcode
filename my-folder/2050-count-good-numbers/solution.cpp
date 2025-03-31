class Solution {
public:
    long long solve(long long x, long long n, int mod) {
        if (n == 0) return 1;

        long long half = solve(x, n / 2, mod)%mod; 

        half = (half * half) % mod;  
        if (n % 2 == 1) half = (half * x)%mod ;

        return half;
    }

    int countGoodNumbers(long long n) {
        int mod = 1e9+7;  
        long long n1 = n / 2;
        long long n2 = n - n1;

        long long ans = (solve(4, n1, mod) * solve(5, n2, mod)) % mod;
        
        return ans;
    }
};

