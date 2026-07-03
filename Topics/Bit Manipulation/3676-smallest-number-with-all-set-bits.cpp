class Solution {
public:
    int smallestNumber(int n) {
        if(n%2==0 || n==1) n++;
        while((n&(n-1))!=0) n++;
        return n-1;
    }
};
