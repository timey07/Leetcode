class Solution {
public:
    int uniquePaths(int m, int n) {
        int j=1;
        long long ans=1;
        for(int i=m+n-2;i>=max(m,n);--i){
            ans= ans*i/j;
            j++;
        }
        return ans;
    }
};
