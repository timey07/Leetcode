class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n=s.size();
        vector<int> prev(n+1,0);
        string t=s;
        reverse(t.begin(),t.end());
        for(int i=1;i<=n;++i){
            vector<int> curr(n+1,0);
            for(int j=1;j<=n;++j){
                if(s[i-1]==t[j-1]){
                    curr[j]=1+prev[j-1];
                }
                else curr[j]=max(curr[j-1],prev[j]);
            }
            prev=curr;
        }
        return prev[n];
    }
};
