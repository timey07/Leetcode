class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        map<char,int> mp;
        int l=0;
        int r=0;
        int ans=0;
        while(r<s.size()){
            if(!mp[s[r]]) mp[s[r]]++;
            else{
                while(s[r]!=s[l]){
                    mp[s[l]]--;
                    l++;
                }
                l++;
            }
            ans=max(ans,(r-l+1));
            r++;
        }
        return ans;
    }
};
