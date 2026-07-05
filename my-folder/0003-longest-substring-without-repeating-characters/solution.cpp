class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n=s.size();
        unordered_map<char,int> occur;
        int ans=0;
        int left=0;
        for(int i=0;i<n;++i){
            if(left<occur[s[i]]) left=occur[s[i]];
            ans = max(ans,i-left+1);
            occur[s[i]]=i+1;
        }
        return ans;
    }
};
