class Solution {
    public:
    void solve(double x,long long n, double &ans){
        if(n==0) return;
        if(n%2) ans*=x;
        solve(x*x,n/2,ans);
    }
public:
    double myPow(double x, long long n) {
        if(n<0){
            n=-n;
            x=1/x;
        }
        double ans=1.0;
        solve(x,n,ans);
        return ans;
    }
};
