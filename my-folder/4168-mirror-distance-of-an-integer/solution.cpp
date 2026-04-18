class Solution {
public:
    int mirrorDistance(int n) {
        int temp=n;
        int rev=0;
        while(temp){
            rev*=10;
            rev+=(temp%10);
            temp/=10;
        }
        int ans=abs(rev-n);
        return ans;
    }
};
