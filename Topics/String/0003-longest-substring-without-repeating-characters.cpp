class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int low=0;
        map<char,int> mp;
        int n=s.size();
        int ans=0;
        for(int i=0;i<n;++i){
            mp[s[i]]++;
            while(mp[s[i]]==2){
                mp[s[low]]--;
                low++;
            }
            ans=max(ans,i-low+1);
        }
        return ans;
    }
};
