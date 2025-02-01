class Solution {
public:
    int maxDepth(string s) {
        int ans=0;
        int sum=0;
        for(int i=0;i<s.size();++i){
            if(s[i]=='(') sum++;
            if(s[i]==')') sum--;
            ans=max(sum,ans);
        }
        return ans;
    }
};
