class Solution {
public:
    int minInsertions(string s) {
        int n=s.size();
        vector<int> prev(n+1,0);
        for(int i=1;i<=n;++i){
            vector<int>curr(n+1,0);
            for(int j=1;j<=n;++j){
                if(s[i-1]==s[n-j]) curr[j]=1+prev[j-1];
                else curr[j]=max(curr[j-1],prev[j]);
            }
            prev=curr;
        }
        if(prev[n]==0) return 0;
        int ans=n-prev[n];
        return ans;
    }
};
