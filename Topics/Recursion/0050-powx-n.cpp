class Solution {
public:
    double myPow(double x, long long n) {
        double ans=1;
        if(n<0){
            n=-(n);
            x=1/x;
        }
        while(n){
            if(n%2==0){
                x*=x;
                n/=2;
            }
            ans*=x;
            n--;
        }
        return ans;
    }
};
