class Solution {
public:
    int countBinarySubstrings(string s) {
        int ans=0;
        int n=s.size();
        int sum=1;
        int prevsum=0;
        for(int i=1;i<n;++i){
            if(s[i]==s[i-1]) sum++;
            else{
                prevsum=sum;
                sum=1;
            }
            if(sum<=prevsum) ans++;
        }
        return ans;
    }
};
