class Solution {
    public:
    double solve(double x,long long n){
        if(n==0) return 1;
        if(n%2) return solve(x*x,n/2)*x;
        return solve(x*x,n/2);
    }
public:
    double myPow(double x, long long n) {
        if(n<0){
            n=-n;
            x=1/x;
        }
        double ans=1.0;
        return solve(x,n);
    }
};
