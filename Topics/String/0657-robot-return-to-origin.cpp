class Solution {
public:
    bool judgeCircle(string s) {
        int sum1=0;
        int sum2=0;
        int n=s.size();
        for(int i=0;i<n;++i){
            if(s[i]=='U') sum1++;
            if(s[i]=='R') sum2++;
            if(s[i]=='D') sum1--;
            if(s[i]=='L') sum2--;
        }
        if(sum1 || sum2) return false;
        else return true;
    }
};
