class Solution {
    public:
    double solve(double x, long n){
        if(n==0) return 1;
        double half=solve(x,n/2);
        if(n%2==0) return half*half;
        else return half*half*x;
    }
public:
    double myPow(double x, long n) {
        if(n<0) return solve(1/x,-n);
        else return solve(x,n);
    }
};
